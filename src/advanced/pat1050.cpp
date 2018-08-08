//
// Created by neild47 on 18-6-14.
//
#include <iostream>

using namespace std;

namespace pat1050 {

    bool count0[300];

    int main() {
        string s;
        getline(cin, s);
        string ss;
        getline(cin, ss);
        for (auto c:ss) {
            count0[c] = true;
        }

        for (auto c:s) {
            if (!count0[c]) {
                printf("%c", c);
            }
        }
        return 0;
    }
}
