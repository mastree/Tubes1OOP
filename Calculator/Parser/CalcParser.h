#ifndef CALCPARSER_H
#define CALCPARSER_H

#include <QMainWindow>
#include <bits/stdc++.h>
#include "../Exception/Exception.h"

using namespace std;

class CalcParser
{
private:
    int len = 0;
    queue <pair<int, string>> token; // Jenis, value;
    // num = 0, op = 1;
public:
    CalcParser(string s);

    pair<int, string> nextContent();

    bool empty();

    int getLen();
};


//====================================================
// *** REALISASI ***
//====================================================

CalcParser::CalcParser(string s){
    stringstream ss(s);
    string temp;
    while (ss >> temp){
        len++;
        if (('0' <= temp[0] && temp[0] <= '9') || temp[0] == '.' || (temp[0] == '-' && temp.length() > 1)){
            int cnt = 0;
            for (char isi : temp){
                if (isi == '.') cnt++;
            }
            if (cnt >= 2) throw new InvalidNumber();
            token.push(make_pair(0, temp));
        } else{
            token.push(make_pair(1, temp));
        }
    }
}

pair<int, string> CalcParser::nextContent(){
    pair<int, string> ret = token.front();
    token.pop();
    len--;
    return ret;
}

bool CalcParser::empty(){
    return (len == 0);
}

int CalcParser::getLen(){
    return len;
}

#endif // CALCPARSER_H
