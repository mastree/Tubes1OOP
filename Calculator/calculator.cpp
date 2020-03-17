#include "calculator.h"
#include "./ui_calculator.h"
#include <bits/stdc++.h>

using namespace std;

double curVal = 0.0;

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui -> setupUi(this);
    ui -> Display -> setText(QString::number(curVal));
    QPushButton *numButtons[10];

    for (int i=0;i<10;i++){
        QString name = "Button_" + QString::number(i);
        numButtons[i] = Calculator::findChild<QPushButton *>(name);
        connect(numButtons[i], SIGNAL(released()), this, SLOT(NumPressed()));
    }
    connect(ui->Button_Point, SIGNAL(released()), this, SLOT(PointPressed()));
    connect(ui->Button_Add, SIGNAL(released()), this, SLOT(BinaryOpPressed()));
    connect(ui->Button_Subtract, SIGNAL(released()), this, SLOT(BinaryOpPressed()));
    connect(ui->Button_Multiply, SIGNAL(released()), this, SLOT(BinaryOpPressed()));
    connect(ui->Button_Divide, SIGNAL(released()), this, SLOT(BinaryOpPressed()));
    connect(ui->Button_Equal, SIGNAL(released()), this, SLOT(EqPressed()));
    connect(ui->Button_Sqrt, SIGNAL(released()), this, SLOT(UnaryOpPressed()));
    connect(ui->Button_Sin, SIGNAL(released()), this, SLOT(UnaryOpPressed()));
    connect(ui->Button_Cos, SIGNAL(released()), this, SLOT(UnaryOpPressed()));
    connect(ui->Button_Tan, SIGNAL(released()), this, SLOT(UnaryOpPressed()));
    connect(ui->Button_Cot, SIGNAL(released()), this, SLOT(UnaryOpPressed()));

    setWindowTitle(tr("Calculator OOP"));
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::NumPressed(){
    QPushButton *button = (QPushButton *)sender();
    QString num = button -> text();
    QString display = ui -> Display -> text();
    
    if (display == "0" || display == "0.0"){
        ui -> Display -> setText(num);
    } else{
        QString baru = display + num;
        ui -> Display -> setText(baru);
    }
}

void Calculator::BinaryOpPressed(){
    QPushButton *button = (QPushButton *)sender();
    QString op = button -> text();
    QString display = ui -> Display -> text();
 
    QString baru = display + " " + op + " ";
    ui -> Display -> setText(baru);
}

void Calculator::EqPressed(){
    CalcParser *content = new CalcParser((ui -> Display -> text()).toStdString());

    if (content -> empty()) return;

    double curSum = 0;
    double curMulti = 0;

    pair <int, string> now = content -> nextContent();
    if (now.first != 0){
        throw "Invalid expression: Tidak dimulai dengan angka";
    }

    if (content -> getLen() % 2){
        throw "Invalid expression: Jumlah operator dan angka tidak seimbang";
    }

    string lastMultiOP = "";
    string lastSumOP = "";
    int id = 0;
    while(!(content -> empty())){
        if (now.first == 0 && (id & 1) == 0){
            if (lastMultiOP == ""){
                curMulti = stod(now.second);
            } else{
                if (lastMultiOP == "*"){
                    curMulti *= stod(now.second);
                } else{
                    curMulti = curMulti / stod(now.second);
                }
                lastMultiOP = "";
            }
        } else if (now.first == 1 && (id & 1)){
            if (now.second == "+" || now.second == "-"){
                if (lastSumOP == "+" || lastSumOP == ""){
                    curSum += curMulti;
                } else{
                    curSum -= curMulti;
                }
                lastMultiOP = "";
                lastSumOP = now.second;
            } else{
                lastMultiOP = now.second;
            }
        } else{
            throw "Invalid expression: Consecutive operator";
        }
        id++;
        now = content -> nextContent();
    }
    if (now.first == 0 && (id & 1) == 0){
        if (lastMultiOP == ""){
            curMulti = stod(now.second);
        } else{
            if (lastMultiOP == "*"){
                curMulti *= stod(now.second);
            } else{
                curMulti = curMulti / stod(now.second);
            }
            lastMultiOP = "";
        }
    } else if (now.first == 1 && (id & 1)){
        if (now.second == "+" || now.second == "-"){
            if (lastSumOP == "+" || lastSumOP == ""){
                curSum += curMulti;
            } else{
                curSum -= curMulti;
            }
            lastMultiOP = "";
            lastSumOP = now.second;
        } else{
            lastMultiOP = now.second;
        }
    } else{
        throw "Invalid expression: Consecutive operator";
    }
    if (lastSumOP == "+" || lastSumOP == ""){
        curSum += curMulti;
    } else{
        curSum -= curMulti;
    }

    curVal = curSum;
    ui -> Display -> setText(QString::number(curVal, 'g', 16));
}

void Calculator::UnaryOpPressed(){
    QPushButton *button = (QPushButton *)sender();
    QString op = button -> text();
    
    EqPressed();
    if (op == "sqrt"){
        curVal = sqrt(curVal);
    } else if (op == "sin"){
        curVal = sin(curVal);
    } else if (op == "cos"){
        curVal = sin(curVal);
    } else if (op == "tan"){
        curVal = tan(curVal);
    } else{
        curVal = 1.0 / tan(curVal);
    }
    ui -> Display -> setText(QString::number(curVal, 'g', 16));
}

void Calculator::PointPressed(){
    QPushButton *button = (QPushButton *)sender();
    QString num = button -> text();
    QString display = ui -> Display -> text();
    
    if (display == "0" || display == "0.0"){
        ui -> Display -> setText("0" + num);
    } else{
        QString baru = display + num;
        ui -> Display -> setText(baru);
    }
}
