#include <bits/stdc++.h>
#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
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


TEST_CASE( "Parser running", "[Parsed]" ) {
    CalcParser isi("1 + -123 - 13 * 1.00 - 5");
    REQUIRE( isi.nextContent() == make_pair(0, (string)"1") );
    REQUIRE( isi.nextContent() == make_pair(1, (string)"+") );
    REQUIRE( isi.nextContent() == make_pair(0, (string)"-123") );
    REQUIRE( isi.getLen() == 6 );
    REQUIRE( isi.nextContent() == make_pair(1, (string)"-") );
    REQUIRE( isi.nextContent() == make_pair(0, (string)"13") );
    REQUIRE( isi.empty() == false );
    REQUIRE( isi.nextContent() == make_pair(1, (string)"*") );
    REQUIRE( isi.getLen() == 3 );
    REQUIRE( isi.nextContent() == make_pair(0, (string)"1.00") );
    REQUIRE( isi.nextContent() == make_pair(1, (string)"-") );
    REQUIRE( isi.nextContent() == make_pair(0, (string)"5") );
    REQUIRE( isi.empty() == true );
}