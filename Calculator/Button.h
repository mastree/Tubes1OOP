// INI BELUM SELESAI, MASIH ERROR TERUS


#ifndef BUTTON_H
#define BUTTON_H

#include <QMainWindow>
#include <bits/stdc++.h>

using namespace std;

class Button{
Q_OBJECT

public:
    virtual void onClick() = 0;
};

class NumButton : public Button{
public:
    void onClick(Calculator* calc){
        QPushButton *button = (QPushButton *)calc -> sender();
        QString num = button -> text();
        QString display = calc -> ui -> Display -> text();

        if (clearDisplay){
            if (display == "0" || display == "0.0"){
                calc -> ui -> Display -> setText(num);
            } else{
                QString baru = display + num;
                calc -> ui -> Display -> setText(baru);
            }
        } else if (!opPressed){
            calc -> ui -> Display -> setText(num);
            calc -> clearDisplay = 1;
        }
        calc -> opPressed = 0;
    }
};

#endif
