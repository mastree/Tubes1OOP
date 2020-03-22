#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <bits/stdc++.h>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
    class Calculator;
    class CalcParser;
}
QT_END_NAMESPACE

class Calculator : public QMainWindow {
    Q_OBJECT

public:

    Calculator(QWidget *parent = nullptr); // nullptr = 0
    ~Calculator();

protected:
    const long double PI;
    long double curVal; // Bilangan yang terakhir dihitung
    long double lastAns; // Bilangan yang akan keluar bila tombol "ans" ditekan
    bool opPressed; // Menandakan apakah tombol terakhir yang ditekan adalah sebuah operator
    bool storedAnsExist; // Menandakan apakah ada memori yang disimpan
    bool clearDisplay;
    bool isError;
    long double DisplayValue(); // Mengembalikan nilai expression yang ada dilayar

    queue <long double> listOfAns; // Menyimpan memori nilai-nilai yang disimpan

private:
    Ui::Calculator *ui;

private slots:
    void NumPressed(); // Menerima signal tombol angka 
    void BinaryOpPressed(); // Menerima signal tombol operasi biner 
    void EqPressed(); // Menerima signal tombol sama dengan
    void UnaryOpPressed(); // Menerima signal tombol operasi uner
    void PointPressed(); // Menerima signal tombol titik 
    void AnsPressed(); // Menerima signal tombol ans 
    void CLEARPressed(); // Menerima signal tombol clear
    void MRPressed(); // Menerima signal tombol MR
    void MCPressed(); // Menerima signal tombol MC
};
#endif // CALCULATOR_H
