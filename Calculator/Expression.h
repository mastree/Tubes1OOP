#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <bits/stdc++.h>

using namespace std;
class Expression {

public :
    virtual long double solve() = 0;

};

class TerminalExpression : public Expression{

protected:
    long double x;
public :
    TerminalExpression(long double x);
    long double solve();

};

class UnaryExpression : public Expression{

protected:
    Expression* x;
public:
    UnaryExpression(Expression* x);
    virtual long double solve() = 0;
};

class BinaryExpression : public Expression{


protected:
    Expression* x;
    Expression* y;

public:
    BinaryExpression(Expression* x, Expression* y);
    virtual long double solve() = 0;
};

class SquareRootExpression : public UnaryExpression {
public:
    SquareRootExpression(Expression *x);
    long double solve();
};

class SinExpression : public UnaryExpression {
public:
    SinExpression(Expression *x);
    long double solve();
};


class CosExpression : public UnaryExpression {
public:
    CosExpression(Expression *x);
    long double solve();
};

class TanExpression : public UnaryExpression {
public:
    TanExpression(Expression *x);
    long double solve();
};

class CotExpression : public UnaryExpression {
public:
    CotExpression(Expression *x);
    long double solve();
};


class AddExpression : public BinaryExpression {

public:
    AddExpression(Expression *x, Expression *y);
    long double solve();
};

class SubtractExpression : public BinaryExpression{

public:
    SubtractExpression(Expression *x,Expression *y);
    long double solve();
};

class MultiplyExpression : public BinaryExpression{
public:
    MultiplyExpression(Expression *x, Expression *y);
    long double solve();
};

class DivideExpression : public BinaryExpression{

public:
    DivideExpression(Expression *x, Expression *y);
    long double solve();
};

class PowerExpression : public BinaryExpression{

public:
    PowerExpression(Expression *x, Expression *y);
    long double solve();
};

TerminalExpression::TerminalExpression(long double x){
    this->x = x;
}

long double TerminalExpression::solve(){
    return this->x;
}

UnaryExpression::UnaryExpression(Expression *x){
    this->x = x;
}

BinaryExpression::BinaryExpression(Expression *x, Expression *y){
    this->x = x;
    this->y = y;
}

SquareRootExpression::SquareRootExpression(Expression *x) : UnaryExpression(x){}


long double SquareRootExpression::solve() {
    long double answ = this->x->solve();
    return sqrt(answ);
}

SinExpression::SinExpression(Expression *x): UnaryExpression(x) {}

long double SinExpression::solve(){
    long double answ = this->x->solve();
    return sin(answ);
}

CosExpression::CosExpression(Expression *x):UnaryExpression(x){}

long double CosExpression::solve(){
    long double answ = this->x->solve();
    return cos(answ);
}

TanExpression::TanExpression(Expression *x):UnaryExpression(x){}

long double TanExpression::solve(){
    long double answ = this->x->solve();
    return tan(answ);
}

CotExpression::CotExpression(Expression *x):UnaryExpression(x){}

long double CotExpression::solve(){
    long double answ = this->x->solve();
    return 1/tan(answ);
}

AddExpression::AddExpression(Expression *x,Expression *y ) :BinaryExpression(x,y){

}
long double AddExpression::solve(){
    long double solutionX = this->x->solve();
    long double solutionY = this->y->solve();
    long double result = solutionX + solutionY;
    return(result);
}

SubtractExpression::SubtractExpression(Expression *x, Expression *y): BinaryExpression(x, y){}

long double SubtractExpression::solve(){
    long double solutionX = this->x->solve();
    long double solutionY = this->y->solve();
    long double result = solutionX - solutionY;
    return(result);
}

MultiplyExpression::MultiplyExpression(Expression *x, Expression *y) : BinaryExpression(x,y){}

long double MultiplyExpression::solve(){
    long double solutionX = this->x->solve();
    long double solutionY = this->y->solve();
    long double result = solutionX * solutionY;
    return(result);
}

DivideExpression::DivideExpression(Expression *x, Expression *y) : BinaryExpression(x,y){}
long double DivideExpression::solve(){
    long double solutionX = this->x->solve();
    long double solutionY = this->y->solve();
    long double result = solutionX / solutionY;
    return(result);
}

PowerExpression::PowerExpression(Expression *x, Expression *y) : BinaryExpression(x, y){}
long double PowerExpression::solve(){
    long double solutionX = this->x->solve();
    long double solutionY = this->y->solve();
    long double result = pow(solutionX,solutionY);
    return(result);
}


#endif // EXPRESSION_H