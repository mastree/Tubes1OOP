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
    string errorMessage() {
        return "Tidak dimulai dengan angka";
    }
};

class ImbalanceSymbol : public BaseException {
private:
public:
    string errorMessage() {
        return "Jumlah operator dan angka tidak seimbang";
    }
};

class ConsecutiveSymbol : public BaseException {
private:
public:
    string errorMessage() {
        return "Operator beruntun";
    }
};

class InvalidNumber : public BaseException {
private:
public:
    string errorMessage() {
        return "Angka tidak valid";
    }
};

class DivisionByZero : public BaseException {
private:
public:
    string errorMessage() {
        return "Pembagian dengan bilangan nol";
    }
};

#endif
