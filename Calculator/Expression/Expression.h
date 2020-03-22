#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <bits/stdc++.h>
#include "../Exception/Exception.h"

using namespace std;

template<class T>
class Expression {

public :
    virtual T solve() = 0;
};

template <class T>
class TerminalExpression : public Expression<T>{

protected:
    T x;
public :
    TerminalExpression(T x);
    T solve();

};

template <class T>
class UnaryExpression : public Expression<T>{

protected:
    Expression<T>* x;
public:
    UnaryExpression(Expression<T>* x);
    virtual T solve() = 0;
};


template <class T>
class BinaryExpression : public Expression<T>{


protected:
    Expression<T>* x;
    Expression<T>* y;

public:
    BinaryExpression(Expression<T>* x, Expression<T>* y);
    virtual T solve() = 0;
};

template<class T>
class SquareRootExpression : public UnaryExpression<T> {
public:
    SquareRootExpression(Expression<T> *x);
    T solve();
};

template<class T>
class SinExpression : public UnaryExpression<T> {
public:
    SinExpression(Expression<T> *x);
    T solve();
};

template<class T>
class CosExpression : public UnaryExpression<T> {
public:
    CosExpression(Expression<T> *x);
    T solve();
};

template<class T>
class TanExpression : public UnaryExpression<T> {
public:
    TanExpression(Expression<T> *x);
    T solve();
};

template<class T>
class CotExpression : public UnaryExpression<T> {
public:
    CotExpression(Expression<T> *x);
    T solve();
};

template<class T>
class AddExpression : public BinaryExpression<T> {

public:
    AddExpression(Expression<T> *x, Expression<T> *y);
    T solve();
};

template<class T>
class SubtractExpression : public BinaryExpression<T>{

public:
    SubtractExpression(Expression<T> *x,Expression<T> *y);
    T solve();
};

template<class T>
class MultiplyExpression : public BinaryExpression<T>{
public:
    MultiplyExpression(Expression<T> *x, Expression<T> *y);
    T solve();
};

template<class T>
class DivideExpression : public BinaryExpression<T>{

public:
    DivideExpression(Expression<T> *x, Expression<T> *y);
    T solve();
};

template<class T>
class PowerExpression : public BinaryExpression<T>{

public:
    PowerExpression(Expression<T> *x, Expression<T> *y);
    T solve();
};



//====================================================
// *** REALISASI ***
//====================================================
template<class T>
TerminalExpression<T>::TerminalExpression(T x){
    this->x = x;
}

template<class T>
T TerminalExpression<T>::solve(){
    return this->x;
}

template<class T>
UnaryExpression<T>::UnaryExpression(Expression<T> *x){
    this->x = x;
}

template<class T>
BinaryExpression<T>::BinaryExpression(Expression<T> *x, Expression<T> *y){
    this->x = x;
    this->y = y;
}

template<class T>
SquareRootExpression<T>::SquareRootExpression(Expression<T> *x) : UnaryExpression<T>(x){}

template<class T>
T SquareRootExpression<T>::solve() {
    T answ = this->x->solve();
    if (answ < 0){
        throw new ImaginaryNumber();
    }
    return sqrt(answ);
}

template<class T>
SinExpression<T>::SinExpression(Expression<T> *x): UnaryExpression<T>(x) {}

template<class T>
T SinExpression<T>::solve(){
    T answ = this->x->solve();
    return sin(answ);
}

template<class T>
CosExpression<T>::CosExpression(Expression<T> *x):UnaryExpression<T>(x){}

template<class T>
T CosExpression<T>::solve(){
    T answ = this->x->solve();
    return cos(answ);
}

template<class T>
TanExpression<T>::TanExpression(Expression<T> *x):UnaryExpression<T>(x){}


template<class T>
T TanExpression<T>::solve(){
    T answ = this->x->solve();
    return tan(answ);
}

template<class T>
CotExpression<T>::CotExpression(Expression<T> *x):UnaryExpression<T>(x){}

template<class T>
T CotExpression<T>::solve(){
    T answ = this->x->solve();
    return 1/tan(answ);
}

template<class T>
AddExpression<T>::AddExpression(Expression<T> *x,Expression<T> *y ) :BinaryExpression<T>(x,y){

}
template<class T>
T AddExpression<T>::solve(){
    T solutionX = this->x->solve();
    T solutionY = this->y->solve();
    T result = solutionX + solutionY;
    return(result);
}

template<class T>
SubtractExpression<T>::SubtractExpression(Expression<T> *x, Expression<T> *y): BinaryExpression<T>(x, y){}

template<class T>
T SubtractExpression<T>::solve(){
    T solutionX = this->x->solve();
    T solutionY = this->y->solve();
    T result = solutionX - solutionY;
    return(result);
}

template<class T>
MultiplyExpression<T>::MultiplyExpression(Expression<T> *x, Expression<T> *y) : BinaryExpression<T>(x,y){}

template<class T>
T MultiplyExpression<T>::solve(){
    T solutionX = this->x->solve();
    T solutionY = this->y->solve();
    T result = solutionX * solutionY;
    return(result);
}

template<class T>
DivideExpression<T>::DivideExpression(Expression<T> *x, Expression<T> *y) : BinaryExpression<T>(x,y){}

template<class T>
T DivideExpression<T>::solve(){
    T solutionX = this->x->solve();
    T solutionY = this->y->solve();
    if (solutionY == 0){
        throw new DivisionByZero();
    }
    T result = solutionX / solutionY;
    return(result);
}

template<class T>
PowerExpression<T>::PowerExpression(Expression<T> *x, Expression<T> *y) : BinaryExpression<T>(x, y){}
template<class T>
T PowerExpression<T>::solve(){
    T solutionX = this->x->solve();
    T solutionY = this->y->solve();
    T result = pow(solutionX,solutionY);
    return(result);
}


#endif // EXPRESSION_H
