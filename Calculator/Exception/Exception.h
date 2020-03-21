#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
using namespace std;

class BaseException {
public:
    virtual string errorMessage() = 0;
};

class InvalidStartSymbol : public BaseException {
private:
public:
    string errorMessage();
};

class ImbalanceSymbol : public BaseException {
private:
public:
    string errorMessage();
};

class ConsecutiveSymbol : public BaseException {
private:
public:
    string errorMessage();
};

class InvalidNumber : public BaseException {
private:
public:
    string errorMessage();
};

class DivisionByZero : public BaseException {
private:
public:
    string errorMessage();
};

class ImaginaryNumber : public BaseException {
private:
public:
    string errorMessage();
};


//====================================================
// *** REALISASI ***
//====================================================

string InvalidStartSymbol::errorMessage() {
    return "Tidak dimulai dengan angka";
}

string ImbalanceSymbol::errorMessage() {
    return "Kebanyakan operator";
}

string ConsecutiveSymbol::errorMessage() {
    return "Operator beruntun";
}

string InvalidNumber::errorMessage() {
    return "Angka tidak valid";
}

string DivisionByZero::errorMessage() {
    return "Pembagian bilangan nol";
}

string ImaginaryNumber::errorMessage(){
    return "Bilangan imaginer";
}

#endif
