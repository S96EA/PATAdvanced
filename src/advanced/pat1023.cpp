//
// Created by neild47 on 18-6-5.
//
#include <iostream>
#include <algorithm>

using namespace std;

namespace pat1023 {
    int numsa[10];
    int numsb[10];
    int main() {
        string a;
        getline(cin, a);
        for (auto c:a) {
            numsa[c - '0']++;
        }

        string b = "";
        int c = 0;
        for (auto item = a.rbegin(); item != a.rend(); item++) {
            int n = *item - '0';
            n = n * 2 + c;
            c = n / 10;
            n = n % 10;
            b = to_string(n) + b;
        }
        if (c != 0) {
            b = to_string(c) + b;
        }

        for (auto c:b) {
            numsb[c - '0']++;
        }

        if (equal(numsa, numsa + 10, numsb)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }

        cout << b << endl;
        return 0;
    }
}
