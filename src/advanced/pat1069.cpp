//
// Created by neild47 on 18-6-29.
//
#include <iostream>
#include <algorithm>

using namespace std;

namespace pat1070 {
    int main() {
        int d;
        cin >> d;
        char buf[10];
        sprintf(buf, "%04d", d);
        if (d == 0) {
            cout << "0000 - 0000 = 0000" << endl;
            return 0;
        }
        string s = buf;
        int num = stoi(s);
        while (d || (num != 6174 && num != 0)) {
            sort(s.begin(), s.end(), std::greater<const char>());
            int n1 = stoi(s);
            sort(s.begin(), s.end(), std::less<const char>());
            int n2 = stoi(s);
            num = n1 - n2;
            printf("%04d - %04d = %04d\n", n1, n2, num);
            sprintf(buf, "%04d", num);
            s = buf;
            d = 0;
        }
        return 0;
    }
}

