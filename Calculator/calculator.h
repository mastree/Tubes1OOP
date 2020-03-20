#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <bits/stdc++.h>
// #include "Button.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
    class Calculator;
}
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    const long double PI;

    Calculator(QWidget *parent = nullptr); // nullptr = 0
    ~Calculator();

protected:
    long double curVal; 
    long double lastAns;
    bool opPressed;
    bool storedAnsExist;
    bool clearDisplay;
    bool isError;
    long double DisplayValue();

    queue <long double> listOfAns;

private:
    Ui::Calculator *ui;

private slots:
    void NumPressed();
    void BinaryOpPressed();
    void EqPressed();
    void UnaryOpPressed();
    void PointPressed();
    void AnsPressed();
    void CLEARPressed();
    void MRPressed();
    void MCPressed();

};
#endif // CALCULATOR_H
