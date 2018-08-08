//
// Created by neild47 on 18-7-24.
//
#include <iostream>
#include <string>

using namespace std;
namespace pat1108 {


    bool isLegal(const string &s) {
        int startI = 0;
        if (s[startI] == '-') {
            startI++;
        }
        if (startI == s.size()) return false;
        int dotPos = -1;
        for (int i = startI; i < s.size(); i++) {
            if (!isdigit(s[i])) {
                if (s[i] == '.' && dotPos == -1) {
                    dotPos = i;
                } else {
                    return false;
                }
            }
        }
        if (dotPos != -1) {
            if (s.size() - dotPos - 1 > 2) {
                return false;
            }
        }
        double d = atof(s.data());
        if (d < -1000 || d > 1000) return false;
        return true;
    }

    int main() {
        int n, cnt = 0;
        string s;
        double sNum = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> s;
            if (isLegal(s)) {
                sNum += atof(s.data());
                cnt++;
            } else {
                cout << "ERROR: " << s << " is not a legal number" << endl;
            }
        }

        if (cnt == 0) {
            cout << "The average of 0 numbers is Undefined" << endl;
        } else if (cnt == 1) {
            printf("The average of 1 number is %.2f\n", sNum);
        } else {
            printf("The average of %d numbers is %.2f\n", cnt, sNum / cnt);
        }
        return 0;
    }
}
