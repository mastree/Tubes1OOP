#include "Expression.h"
#include <math.h>

TerminalExpression::TerminalExpression(float x){
    this->x = x;
}

float TerminalExpression::solve(){
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


float SquareRootExpression::solve() {
    float answ = this->x->solve();
    return sqrt(answ);
}

SinExpression::SinExpression(Expression *x): UnaryExpression(x) {}

float SinExpression::solve(){
    float answ = this->x->solve();
    return sin(answ);
}

CosExpression::CosExpression(Expression *x):UnaryExpression(x){}

float CosExpression::solve(){
    float answ = this->x->solve();
    return cos(answ);
}

TanExpression::TanExpression(Expression *x):UnaryExpression(x){}

float TanExpression::solve(){
    float answ = this->x->solve();
    return tan(answ);
}

CotExpression::CotExpression(Expression *x):UnaryExpression(x){}

float CotExpression::solve(){
    float answ = this->x->solve();
    return 1/tan(answ);
}

AddExpression::AddExpression(Expression *x,Expression *y ) :BinaryExpression(x,y){

}
float AddExpression::solve(){
    float solutionX = this->x->solve();
    float solutionY = this->y->solve();
    float result = solutionX + solutionY;
    return(result);
}

SubtractExpression::SubtractExpression(Expression *x, Expression *y): BinaryExpression(x, y){}

float SubtractExpression::solve(){
    float solutionX = this->x->solve();
    float solutionY = this->y->solve();
    float result = solutionX - solutionY;
    return(result);
}

MultiplyExpression::MultiplyExpression(Expression *x, Expression *y) : BinaryExpression(x,y){}

float MultiplyExpression::solve(){
    float solutionX = this->x->solve();
    float solutionY = this->y->solve();
    float result = solutionX * solutionY;
    return(result);
}

DivideExpression::DivideExpression(Expression *x, Expression *y) : BinaryExpression(x,y){}
float DivideExpression::solve(){
    float solutionX = this->x->solve();
    float solutionY = this->y->solve();
    float result = solutionX / solutionY;
    return(result);
}

PowerExpression::PowerExpression(Expression *x, Expression *y) : BinaryExpression(x, y){}
float PowerExpression::solve(){
    float solutionX = this->x->solve();
    float solutionY = this->y->solve();
    float result = pow(solutionX,solutionY);
    return(result);
}
