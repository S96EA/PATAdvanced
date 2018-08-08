//
// Created by neild47 on 18-7-1.
//
#include <iostream>

namespace pat1073B {

    using namespace std;

    struct Number {
        char sign;
        char integer;
        char fraction[10010];
        char expSign;
        int exp;
    };


    void printNum(Number &num) {
        cout << num.sign << endl;
        cout << num.integer << endl;
        cout << num.fraction << endl;
        cout << num.expSign << endl;
        cout << num.exp << endl;
    }

    void outputNum(Number &number) {
        if (number.sign == '-') cout << number.sign;

        if (number.exp == 0) {
            cout << number.integer << ".";
            int c = 0;
            while (number.fraction[c] != 0) {
                cout << number.fraction[c];
                c++;
            }
        } else if (number.expSign == '-') {
            cout << "0.";
            int exp = number.exp - 1;
            while (exp > 0) {
                cout << "0";
                exp--;
            }
            cout << number.integer;
            int c = 0;
            while (number.fraction[c] != 0) {
                cout << number.fraction[c];
                c++;
            }
        } else {//exp>0
            cout << number.integer;
            int c = 0;
            int e = number.exp;
            while (e > 0) {
                if (number.fraction[c] == 0) {
                    cout << 0;
                } else {
                    cout << number.fraction[c];
                    c++;
                }
                e--;
            }
            if (number.fraction[c] != 0) cout << ".";
            while (number.fraction[c] != 0) {
                cout << number.fraction[c++];
            }
        }
    }

    int main() {
        string s;
        cin >> s;
        Number number{};
        number.sign = s[0];
        number.integer = s[1];
        int iter = 3, c = 0;
        while (s[iter] != 'E') {
            number.fraction[c] = s[iter];
            iter++, c++;
        }
        s[c] = 0;
        iter++;
        number.expSign = s[iter];
        iter++;
        sscanf(s.c_str() + iter, "%d", &number.exp);

//    printNum(number);
        outputNum(number);

        return 0;
    }
}
