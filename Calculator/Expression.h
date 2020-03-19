#ifndef EXPRESSION_H
#define EXPRESSION_H

#endif // EXPRESSION_H

#include "CalcParser.h"
#include <bits/stdc++.h>

using namespace std;
class Expression {

public :
    virtual float solve() = 0;

};

class TerminalExpression : public Expression{



protected:
    float x;
public :
    TerminalExpression(float x);
    float solve();

};

class UnaryExpression : public Expression{

protected:
    Expression* x;
public:
    UnaryExpression(Expression* x);
    virtual float solve() = 0;
};

class BinaryExpression : public Expression{


protected:
    Expression* x;
    Expression* y;

public:
    BinaryExpression(Expression* x, Expression* y);
    virtual float solve() = 0;
};

class SquareRootExpression : public UnaryExpression {
public:
    SquareRootExpression(Expression *x);
    float solve();
};

class SinExpression : public UnaryExpression {
public:
    SinExpression(Expression *x);
    float solve();
};


class CosExpression : public UnaryExpression {
public:
    CosExpression(Expression *x);
    float solve();
};

class TanExpression : public UnaryExpression {
public:
    TanExpression(Expression *x);
    float solve();
};

class CotExpression : public UnaryExpression {
public:
    CotExpression(Expression *x);
    float solve();
};


class AddExpression : public BinaryExpression {

public:
    AddExpression(Expression *x, Expression *y);
    float solve();
};

class SubtractExpression : public BinaryExpression{

public:
    SubtractExpression(Expression *x,Expression *y);
    float solve();
};

class MultiplyExpression : public BinaryExpression{
public:
    MultiplyExpression(Expression *x, Expression *y);
    float solve();
};

class DivideExpression : public BinaryExpression{

public:
    DivideExpression(Expression *x, Expression *y);
    float solve();
};

class PowerExpression : public BinaryExpression{

public:
    PowerExpression(Expression *x, Expression *y);
    float solve();
};
