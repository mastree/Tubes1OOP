#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include "CalcParser.h"

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
    Calculator(QWidget *parent = nullptr); // nullptr = 0
    ~Calculator();

private:
    Ui::Calculator *ui;

private slots:
    void NumPressed();
    void OpPressed();
    void EqPressed();
    void SqrtPressed();
    void PointPressed();
};
#endif // CALCULATOR_H
