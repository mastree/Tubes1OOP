#include "calculator.h"
#include "./ui_calculator.h"
#include "Expression.h"
Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
    , curVal(0.0)
    , opPressed(0)
    , storedAnsExist(0)
    , clearDisplay(1)
    , PI(acos(-1))
    , isError(0)
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
    connect(ui->Button_Ans, SIGNAL(released()), this, SLOT(AnsPressed()));
    connect(ui->Button_AC, SIGNAL(released()), this, SLOT(ACPressed()));
    connect(ui->Button_MR, SIGNAL(released()), this, SLOT(MRPressed()));
    connect(ui->Button_MC, SIGNAL(released()), this, SLOT(MCPressed()));

    setWindowTitle(tr("Calculator OOP"));
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::NumPressed(){
    if (isError){
        return;
    }
    QPushButton *button = (QPushButton *)sender();
    QString num = button -> text();
    QString display = ui -> Display -> text();

    if (clearDisplay){
        if (display == "0" || display == "0.0"){
            ui -> Display -> setText(num);
        } else{
            QString baru = display + num;
            ui -> Display -> setText(baru);
        }
    } else if (!opPressed){
        ui -> Display -> setText(num);
        clearDisplay = 1;
    }
    opPressed = 0;
}

void Calculator::BinaryOpPressed(){
    if (isError){
        return;
    }
    QPushButton *button = (QPushButton *)sender();
    QString op = button -> text();
    QString display = ui -> Display -> text();

    QString baru = display + " " + op + " ";
    ui -> Display -> setText(baru);
    clearDisplay = 1;
    opPressed = 1;
}

void Calculator::EqPressed(){
    if (isError){
        return;
    }
    double curSum;

    try{
        curSum = DisplayValue();
    } catch (const char * er){
        QString mass = er;
        ui -> Display -> setText(mass);
        isError = 1;
        return;
    }

    curVal = curSum;
    lastAns = curVal;
    ui -> Display -> setText(QString::number(curVal, 'g', 16));
    clearDisplay = 0;
    opPressed = 0;
    storedAnsExist = 1;
}

void Calculator::UnaryOpPressed(){
    if (isError){
        return;
    }
    QPushButton *button = (QPushButton *)sender();
    QString op = button -> text();
    double curSum;

    try{
        curSum = DisplayValue();
    } catch (const char * er){
        QString mass = er;
        ui -> Display -> setText(mass);
        isError = 1;
        return;
    }

    curVal = curSum;
    if (op == "sqrt"){
        TerminalExpression x(curVal);
        SquareRootExpression sq(&x);
//        curVal = sqrt(curVal);
        curVal = sq.solve();
    } else if (op == "sin"){
        curVal = curVal * PI / 180;
        TerminalExpression x(curVal);
        SinExpression sin(&x);
        curVal = sin.solve();
//        curVal = sin(curVal * PI / 180);
    } else if (op == "cos"){
        curVal = curVal * PI / 180;
        TerminalExpression x(curVal);
        CosExpression cos(&x);
        curVal = cos.solve();
//        curVal = cos(curVal * PI / 180);
    } else if (op == "tan"){
//        curVal = tan(curVal * PI / 180);
        curVal = curVal * PI / 180;
        TerminalExpression x(curVal);
        TanExpression tan(&x);
        curVal = tan.solve();
    } else{
        curVal = curVal * PI / 180;
        TerminalExpression x(curVal);
        CotExpression cot(&x);
        curVal = cot.solve();
//        curVal = 1.0 / tan(curVal * PI / 180);
    }
    lastAns = curVal;
    ui -> Display -> setText(QString::number(curVal, 'g', 16));
    clearDisplay = 0;
    opPressed = 0;
    storedAnsExist = 1;
}

void Calculator::PointPressed(){
    if (isError){
        return;
    }
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

void Calculator::AnsPressed(){
    if (isError){
        return;
    }
    QString display = ui -> Display -> text();
    if (storedAnsExist){
        if (opPressed){
            ui -> Display -> setText(display + QString::number(lastAns, 'g', 16));
        } else{
            ui -> Display -> setText(QString::number(lastAns, 'g', 16));
        }
        opPressed = 0;
    }
}

void Calculator::ACPressed(){
    isError = 0;
    curVal = 0;
    opPressed = 0;
    clearDisplay = 1;
    ui -> Display -> setText("0");
}

void Calculator::MRPressed(){
    if (isError){
        return;
    }
    if (listOfAns.empty()) return;

    double curAns = listOfAns.front();
    listOfAns.pop();

    QString display = ui -> Display -> text();
    if (opPressed){
        ui -> Display -> setText(display + QString::number(curAns, 'g', 16));
    } else{
        ui -> Display -> setText(QString::number(curAns, 'g', 16));
    }
    opPressed = 0;
}

void Calculator::MCPressed(){
    if (isError){
        return;
    }
    double curSum;

    try{
        curSum = DisplayValue();
    } catch (const char * er){
        QString mass = er;
        ui -> Display -> setText(mass);
        isError = 1;
        return;
    }
    listOfAns.push(curSum);
}

double Calculator::DisplayValue(){
    CalcParser *content = new CalcParser((ui -> Display -> text()).toStdString());

    if (content -> empty()) return 0;

    double curSum = 0;
    double curMulti = 0;

    pair <int, string> now = content -> nextContent();
    if (now.first != 0){
        if (now.second != "-" || content -> empty()){
            throw "Invalid expression: Tidak dimulai dengan angka";
        } else {
            now = content -> nextContent();
            if (now.first != 0){
                throw "Invalid expression: Tidak dimulai dengan angka";
            } else{
                now.second = "-" + now.second;
            }
        }
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

//                    curMulti *= stod(now.second);
                    TerminalExpression x(curMulti);
                    TerminalExpression y(stod(now.second));
                    MultiplyExpression mult(&x,&y);
                    curMulti = mult.solve();
                } else{
                    if (stod(now.second) == 0){
                        throw "Error: Division by zero";
                    }

//                    curMulti = curMulti / stod(now.second);
                    TerminalExpression x(curMulti);
                    TerminalExpression y(stod(now.second));
                    DivideExpression div(&x,&y);
                    curMulti = div.solve();
                }
                lastMultiOP = "";
            }
        } else if (now.first == 1 && (id & 1)){
            if (now.second == "+" || now.second == "-"){
                if (lastSumOP == "+" || lastSumOP == ""){
//                    curSum += curMulti;
                    TerminalExpression x(curSum);
                    TerminalExpression y(curMulti);
                    AddExpression add(&x,&y);
                    curSum = add.solve();


                } else{
//                    curSum -= curMulti;
                    TerminalExpression x(curSum);
                    TerminalExpression y(curMulti);
                    SubtractExpression sub(&x,&y);
                    curSum = sub.solve();

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
//                curMulti *= stod(now.second);
                TerminalExpression x(curMulti);
                TerminalExpression y(stod(now.second));
                MultiplyExpression mult(&x,&y);
                curMulti = mult.solve();
            } else{
                if (stod(now.second) == 0){
                    throw "Error: Division by zero";
                }
//                curMulti = curMulti / stod(now.second);
                TerminalExpression x(curMulti);
                TerminalExpression y(stod(now.second));
                DivideExpression div(&x,&y);
                curMulti = div.solve();
            }
            lastMultiOP = "";
        }
    } else if (now.first == 1 && (id & 1)){
        if (now.second == "+" || now.second == "-"){
            if (lastSumOP == "+" || lastSumOP == ""){
//                curSum += curMulti;
                TerminalExpression x(curSum);
                TerminalExpression y(curMulti);
                AddExpression add(&x,&y);
                curSum = add.solve();
            } else{
//                curSum -= curMulti;
                TerminalExpression x(curSum);
                TerminalExpression y(curMulti);
                SubtractExpression sub(&x,&y);
                curSum = sub.solve();
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
//        curSum += curMulti;
        TerminalExpression x(curSum);
        TerminalExpression y(curMulti);
        AddExpression add(&x,&y);
        curSum = add.solve();
    } else{
//        curSum -= curMulti;
        TerminalExpression x(curSum);
        TerminalExpression y(curMulti);
        SubtractExpression sub(&x,&y);
        curSum = sub.solve();
    }

    return curSum;
}
