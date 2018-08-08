//
// Created by neild47 on 18-6-20.
//
#include <iostream>
#include <map>
#include <set>
#include <vector>

namespace pat1060 {
    using namespace std;

    class Number {
    public:
        string number;
        int order;

        Number(string &s) {
            int dotPos = s.find('.');
            if (dotPos == -1) {
                int i = 0;
                for (; i < s.size() && s[i] == '0'; i++) {}
                if (i == s.size()) {
                    order = 0;
                    number = "0.0";
                } else {
                    order = s.size() - i;
                    number = "0." + s.substr(i);
                }
            } else {
                int i = 0;
                for (; i < dotPos && s[i] == '0'; i++) {}
                if (i == dotPos) {
                    s = "0" + s.substr(dotPos);
                } else {
                    s = s.substr(i);
                }
                dotPos = s.find('.');

                if (dotPos == 1 && s[0] == '0') {
                    order = 0;
                    int i = 2;
                    for (; i < s.size() && s[i] == '0'; i++) {
                        order--;
                    }
                    if (i == s.size()) {
                        number = "0.0";
                        order = 0;
                    } else {
                        number = "0." + s.substr(i);
                    }
                } else {
                    s.erase(s.begin() + dotPos);
                    number = "0." + s;
                    order = dotPos;
                }
            }
        }


        friend ostream &operator<<(ostream &os1, const Number &number1) {
            os1 << number1.number << " " << number1.order;
            return os1;
        }
    };

    bool isEqual(const Number &number1, const Number &number2, int n) {
        if (number1.order != number2.order) return false;
        n += 2;
        for (int i = 0; i < n; i++) {
            char c1 = i < number1.number.size() ? number1.number[i] : '0';
            char c2 = i < number2.number.size() ? number2.number[i] : '0';
            if (i >= number1.number.size() && i >= number2.number.size()) break;
            if (c1 != c2) return false;
        }
        return true;
    }

    void printNum(Number &number1, int n) {
        n += 2;
        for (int i = 0; i < n; i++) {
            char c1 = i < number1.number.size() ? number1.number[i] : '0';
            printf("%c", c1);
        }
        printf("*10^%d", number1.order);
    }


    int main() {
        int n;
        string num1, num2;
        cin >> n >> num1 >> num2;
        Number n1 = num1;
        Number n2 = num2;

        bool isE = isEqual(n1, n2, n);
        cout << (isE ? "YES " : "NO ");
        if (!isE) {
            printNum(n1, n);
            cout << " ";
        }
        printNum(n2, n);
        return 0;
    }
}
