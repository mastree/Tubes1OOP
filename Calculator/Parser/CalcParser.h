#ifndef CALCPARSER_H
#define CALCPARSER_H

#include <QMainWindow>
#include <bits/stdc++.h>
#include "../Exception/Exception.h"

using namespace std;

class CalcParser {
// Class untuk parsing string yang ada di layar kalkulator
private:
    int len = 0; // Banyak token
    queue <pair<int, string>> token; // Pair menandakan Jenis, value. Jenis = 0 menandakan bilangan, Jenis = 1 menandakan operator
public:
    CalcParser(string s); // Constructor yang akan mem-parsing string s
    pair<int, string> nextContent(); // Mengembalikan isi token satu per satu
    bool empty(); // Mengembalikan status kekosongan token
    int getLen(); // Mengembalikan banyak isi token
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
