/********************************************************************************
** Form generated from reading UI file 'calculator.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calculator
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *Button_Divide;
    QPushButton *Button_2;
    QPushButton *Button_Subtract;
    QPushButton *Button_Tan;
    QPushButton *Button_Equal;
    QPushButton *Button_3;
    QPushButton *Button_Point;
    QPushButton *Button_6;
    QPushButton *Button_7;
    QPushButton *Button_Cot;
    QPushButton *Button_MR;
    QPushButton *Button_Multiply;
    QPushButton *Button_Cos;
    QPushButton *Button_8;
    QPushButton *Button_AC;
    QPushButton *Button_5;
    QPushButton *Button_MC;
    QPushButton *Button_1;
    QPushButton *Button_0;
    QPushButton *Button_Add;
    QPushButton *Button_Sqrt;
    QPushButton *Button_Sin;
    QPushButton *Button_9;
    QLineEdit *Display;
    QPushButton *Button_4;
    QPushButton *Button_Ans;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Calculator)
    {
        if (Calculator->objectName().isEmpty())
            Calculator->setObjectName(QString::fromUtf8("Calculator"));
        Calculator->resize(520, 503);
        Calculator->setStyleSheet(QString::fromUtf8("#Display{\n"
"	height: 100px;\n"
"	width: 500px;\n"
"}\n"
"\n"
"QLineEdit{\n"
"	background-color: rgb(158, 199, 155);\n"
"	border: 1px solid gray;\n"
"	color: rgb(0, 0, 0);\n"
"}\n"
"\n"
"QPushButton{\n"
"	background-color: rgb(0, 0, 0);\n"
"	border: 1px solid gray;\n"
"	color: rgb(255, 255, 255);\n"
"	height: 60px;\n"
"}\n"
"\n"
"#Button_Equal{\n"
"	height: 120px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(100, 100, 100);\n"
"	border: 1px white;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: rgb(255, 0, 0);\n"
"	border: 1px solid dark gray;\n"
"	color: rgb(0, 0, 0);\n"
"}"));
        centralwidget = new QWidget(Calculator);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Button_Divide = new QPushButton(centralwidget);
        Button_Divide->setObjectName(QString::fromUtf8("Button_Divide"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Button_Divide->sizePolicy().hasHeightForWidth());
        Button_Divide->setSizePolicy(sizePolicy);
        Button_Divide->setAutoFillBackground(false);
        Button_Divide->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(Button_Divide, 3, 4, 1, 1);

        Button_2 = new QPushButton(centralwidget);
        Button_2->setObjectName(QString::fromUtf8("Button_2"));
        sizePolicy.setHeightForWidth(Button_2->sizePolicy().hasHeightForWidth());
        Button_2->setSizePolicy(sizePolicy);
        Button_2->setAutoFillBackground(false);
        Button_2->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(Button_2, 5, 1, 1, 1);

        Button_Subtract = new QPushButton(centralwidget);
        Button_Subtract->setObjectName(QString::fromUtf8("Button_Subtract"));
        sizePolicy.setHeightForWidth(Button_Subtract->sizePolicy().hasHeightForWidth());
        Button_Subtract->setSizePolicy(sizePolicy);
        Button_Subtract->setAutoFillBackground(false);
        Button_Subtract->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(Button_Subtract, 2, 4, 1, 1);

        Button_Tan = new QPushButton(centralwidget);
        Button_Tan->setObjectName(QString::fromUtf8("Button_Tan"));

        gridLayout->addWidget(Button_Tan, 6, 2, 1, 1);

        Button_Equal = new QPushButton(centralwidget);
        Button_Equal->setObjectName(QString::fromUtf8("Button_Equal"));
        sizePolicy.setHeightForWidth(Button_Equal->sizePolicy().hasHeightForWidth());
        Button_Equal->setSizePolicy(sizePolicy);
        Button_Equal->setAutoFillBackground(false);
        Button_Equal->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(Button_Equal, 5, 4, 2, 1);

        Button_3 = new QPushButton(centralwidget);
        Button_3->setObjectName(QString::fromUtf8("Button_3"));
        sizePolicy.setHeightForWidth(Button_3->sizePolicy().hasHeightForWidth());
        Button_3->setSizePolicy(sizePolicy);
        Button_3->setAutoFillBackground(false);
        Button_3->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(Button_3, 5, 2, 1, 1);

        Button_Point = new QPushButton(centralwidget);
        Button_Point->setObjectName(QString::fromUtf8("Button_Point"));
        sizePolicy.setHeightForWidth(Button_Point->sizePolicy().hasHeightForWidth());
        Button_Point->setSizePolicy(sizePolicy);
        Button_Point->setAutoFillBackground(false);
        Button_Point->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(Button_Point, 4, 3, 1, 1);

        Button_6 = new QPushButton(centralwidget);
        Button_6->setObjectName(QString::fromUtf8("Button_6"));
        sizePolicy.setHeightForWidth(Button_6->sizePolicy().hasHeightForWidth());
        Button_6->setSizePolicy(sizePolicy);
        Button_6->setAutoFillBackground(false);
        Button_6->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(Button_6, 4, 2, 1, 1);

        Button_7 = new QPushButton(centralwidget);
        Button_7->setObjectName(QString::fromUtf8("Button_7"));
        sizePolicy.setHeightForWidth(Button_7->sizePolicy().hasHeightForWidth());
        Button_7->setSizePolicy(sizePolicy);
        Button_7->setAutoFillBackground(false);
        Button_7->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(Button_7, 3, 0, 1, 1);

        Button_Cot = new QPushButton(centralwidget);
        Button_Cot->setObjectName(QString::fromUtf8("Button_Cot"));

        gridLayout->addWidget(Button_Cot, 6, 3, 1, 1);

        Button_MR = new QPushButton(centralwidget);
        Button_MR->setObjectName(QString::fromUtf8("Button_MR"));
        sizePolicy.setHeightForWidth(Button_MR->sizePolicy().hasHeightForWidth());
        Button_MR->setSizePolicy(sizePolicy);
        Button_MR->setAutoFillBackground(false);
        Button_MR->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(Button_MR, 2, 1, 1, 1);

        Button_Multiply = new QPushButton(centralwidget);
        Button_Multiply->setObjectName(QString::fromUtf8("Button_Multiply"));
        sizePolicy.setHeightForWidth(Button_Multiply->sizePolicy().hasHeightForWidth());
        Button_Multiply->setSizePolicy(sizePolicy);
        Button_Multiply->setAutoFillBackground(false);
        Button_Multiply->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(Button_Multiply, 3, 3, 1, 1);

        Button_Cos = new QPushButton(centralwidget);
        Button_Cos->setObjectName(QString::fromUtf8("Button_Cos"));

        gridLayout->addWidget(Button_Cos, 6, 1, 1, 1);

        Button_8 = new QPushButton(centralwidget);
        Button_8->setObjectName(QString::fromUtf8("Button_8"));
        sizePolicy.setHeightForWidth(Button_8->sizePolicy().hasHeightForWidth());
        Button_8->setSizePolicy(sizePolicy);
        Button_8->setAutoFillBackground(false);
        Button_8->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(Button_8, 3, 1, 1, 1);

        Button_AC = new QPushButton(centralwidget);
        Button_AC->setObjectName(QString::fromUtf8("Button_AC"));
        sizePolicy.setHeightForWidth(Button_AC->sizePolicy().hasHeightForWidth());
        Button_AC->setSizePolicy(sizePolicy);
        Button_AC->setAcceptDrops(false);
        Button_AC->setAutoFillBackground(false);
        Button_AC->setStyleSheet(QString::fromUtf8(""));
        Button_AC->setFlat(false);

        gridLayout->addWidget(Button_AC, 2, 0, 1, 1);

        Button_5 = new QPushButton(centralwidget);
        Button_5->setObjectName(QString::fromUtf8("Button_5"));
        sizePolicy.setHeightForWidth(Button_5->sizePolicy().hasHeightForWidth());
        Button_5->setSizePolicy(sizePolicy);
        Button_5->setAutoFillBackground(false);
        Button_5->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(Button_5, 4, 1, 1, 1);

        Button_MC = new QPushButton(centralwidget);
        Button_MC->setObjectName(QString::fromUtf8("Button_MC"));
        sizePolicy.setHeightForWidth(Button_MC->sizePolicy().hasHeightForWidth());
        Button_MC->setSizePolicy(sizePolicy);
        Button_MC->setAutoFillBackground(false);
        Button_MC->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(Button_MC, 2, 2, 1, 1);

        Button_1 = new QPushButton(centralwidget);
        Button_1->setObjectName(QString::fromUtf8("Button_1"));
        sizePolicy.setHeightForWidth(Button_1->sizePolicy().hasHeightForWidth());
        Button_1->setSizePolicy(sizePolicy);
        Button_1->setAutoFillBackground(false);
        Button_1->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(Button_1, 5, 0, 1, 1);

        Button_0 = new QPushButton(centralwidget);
        Button_0->setObjectName(QString::fromUtf8("Button_0"));
        sizePolicy.setHeightForWidth(Button_0->sizePolicy().hasHeightForWidth());
        Button_0->setSizePolicy(sizePolicy);
        Button_0->setAutoFillBackground(false);
        Button_0->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(Button_0, 5, 3, 1, 1);

        Button_Add = new QPushButton(centralwidget);
        Button_Add->setObjectName(QString::fromUtf8("Button_Add"));
        sizePolicy.setHeightForWidth(Button_Add->sizePolicy().hasHeightForWidth());
        Button_Add->setSizePolicy(sizePolicy);
        Button_Add->setAutoFillBackground(false);
        Button_Add->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(Button_Add, 2, 3, 1, 1);

        Button_Sqrt = new QPushButton(centralwidget);
        Button_Sqrt->setObjectName(QString::fromUtf8("Button_Sqrt"));

        gridLayout->addWidget(Button_Sqrt, 4, 4, 1, 1);

        Button_Sin = new QPushButton(centralwidget);
        Button_Sin->setObjectName(QString::fromUtf8("Button_Sin"));

        gridLayout->addWidget(Button_Sin, 6, 0, 1, 1);

        Button_9 = new QPushButton(centralwidget);
        Button_9->setObjectName(QString::fromUtf8("Button_9"));
        sizePolicy.setHeightForWidth(Button_9->sizePolicy().hasHeightForWidth());
        Button_9->setSizePolicy(sizePolicy);
        Button_9->setAutoFillBackground(false);
        Button_9->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(Button_9, 3, 2, 1, 1);

        Display = new QLineEdit(centralwidget);
        Display->setObjectName(QString::fromUtf8("Display"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Display->sizePolicy().hasHeightForWidth());
        Display->setSizePolicy(sizePolicy1);
        Display->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(Display, 0, 0, 1, 5);

        Button_4 = new QPushButton(centralwidget);
        Button_4->setObjectName(QString::fromUtf8("Button_4"));
        sizePolicy.setHeightForWidth(Button_4->sizePolicy().hasHeightForWidth());
        Button_4->setSizePolicy(sizePolicy);
        Button_4->setAutoFillBackground(false);
        Button_4->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(Button_4, 4, 0, 1, 1);

        Button_Ans = new QPushButton(centralwidget);
        Button_Ans->setObjectName(QString::fromUtf8("Button_Ans"));

        gridLayout->addWidget(Button_Ans, 1, 4, 1, 1);

        Calculator->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Calculator);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 520, 21));
        Calculator->setMenuBar(menubar);
        statusbar = new QStatusBar(Calculator);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Calculator->setStatusBar(statusbar);

        retranslateUi(Calculator);

        Button_AC->setDefault(false);


        QMetaObject::connectSlotsByName(Calculator);
    } // setupUi

    void retranslateUi(QMainWindow *Calculator)
    {
        Calculator->setWindowTitle(QCoreApplication::translate("Calculator", "Calculator", nullptr));
        Button_Divide->setText(QCoreApplication::translate("Calculator", ":", nullptr));
        Button_2->setText(QCoreApplication::translate("Calculator", "2", nullptr));
        Button_Subtract->setText(QCoreApplication::translate("Calculator", "-", nullptr));
        Button_Tan->setText(QCoreApplication::translate("Calculator", "tan", nullptr));
        Button_Equal->setText(QCoreApplication::translate("Calculator", "=", nullptr));
        Button_3->setText(QCoreApplication::translate("Calculator", "3", nullptr));
        Button_Point->setText(QCoreApplication::translate("Calculator", ".", nullptr));
        Button_6->setText(QCoreApplication::translate("Calculator", "6", nullptr));
        Button_7->setText(QCoreApplication::translate("Calculator", "7", nullptr));
        Button_Cot->setText(QCoreApplication::translate("Calculator", "cot", nullptr));
        Button_MR->setText(QCoreApplication::translate("Calculator", "MR", nullptr));
        Button_Multiply->setText(QCoreApplication::translate("Calculator", "*", nullptr));
        Button_Cos->setText(QCoreApplication::translate("Calculator", "cos", nullptr));
        Button_8->setText(QCoreApplication::translate("Calculator", "8", nullptr));
        Button_AC->setText(QCoreApplication::translate("Calculator", "AC", nullptr));
        Button_5->setText(QCoreApplication::translate("Calculator", "5", nullptr));
        Button_MC->setText(QCoreApplication::translate("Calculator", "MC", nullptr));
        Button_1->setText(QCoreApplication::translate("Calculator", "1", nullptr));
        Button_0->setText(QCoreApplication::translate("Calculator", "0", nullptr));
        Button_Add->setText(QCoreApplication::translate("Calculator", "+", nullptr));
        Button_Sqrt->setText(QCoreApplication::translate("Calculator", "sqrt", nullptr));
        Button_Sin->setText(QCoreApplication::translate("Calculator", "sin", nullptr));
        Button_9->setText(QCoreApplication::translate("Calculator", "9", nullptr));
        Button_4->setText(QCoreApplication::translate("Calculator", "4", nullptr));
        Button_Ans->setText(QCoreApplication::translate("Calculator", "ans", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Calculator: public Ui_Calculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
