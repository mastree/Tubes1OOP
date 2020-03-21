#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
using namespace std;

class BaseException {
// Base class untuk exception
public:
    virtual string errorMessage() = 0; // Mengembalikan string pesan error
};

class InvalidStartSymbol : public BaseException {
// Class exception bila simbol awal bukan sebuah bilangan
private:
public:
    string errorMessage();
};

class ImbalanceSymbol : public BaseException {
// class exception bila simbol operator kebanyakan
private:
public:
    string errorMessage();
};

class ConsecutiveSymbol : public BaseException {
// Class exception bila ada simbol berurutan
private:
public:
    string errorMessage();
};

class InvalidNumber : public BaseException {
// Class exception bila ada angka yang tidak valid
private:
public:
    string errorMessage();
};

class DivisionByZero : public BaseException {
// Class exception bila ada pembagian dengan 0
private:
public:
    string errorMessage();
};

class ImaginaryNumber : public BaseException {
// Class exception bila ada pengakaran bilangan negatif
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
