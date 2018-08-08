//
// Created by neild47 on 18-7-18.
//
#include <iostream>

using namespace std;
namespace pat1093 {

    char s[100010];

    int main() {
        cin >> s;
        long numPAT = 0, np = 0, npa = 0;
        if (s[0] == 'P') np = 1;

        for (int i = 1; s[i] != '\0'; i++) {
            if (s[i] == 'P') np++;
            else if (s[i] == 'A') npa += np;
            else {
                numPAT += npa;
                numPAT %= 1000000007;
            }
        }
        cout << numPAT << endl;
        return 0;
    }
}
