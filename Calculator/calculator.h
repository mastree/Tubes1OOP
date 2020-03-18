#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include "CalcParser.h"
#include <bits/stdc++.h>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
    class Calculator;
    class CalcParser;
}
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    const double PI;

    Calculator(QWidget *parent = nullptr); // nullptr = 0
    ~Calculator();

protected:
    double curVal;
    double lastAns;
    bool opPressed;
    bool storedAnsExist;
    bool clearDisplay;
    bool isError;

    queue <double> listOfAns;

private:
    Ui::Calculator *ui;

private slots:
    void NumPressed();
    void BinaryOpPressed();
    void EqPressed();
    void UnaryOpPressed();
    void PointPressed();
    void AnsPressed();
    void ACPressed();
    void MRPressed();
    void MCPressed();

    double DisplayValue();
};
#endif // CALCULATOR_H
