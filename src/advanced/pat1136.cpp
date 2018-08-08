//
// Created by neild47 on 18-8-6.
//

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

namespace pat1136 {

    bool isPalindrome(const string &s1) {
        for (int i = 0; i < s1.size() / 2; i++) {
            if (s1[i] != s1[s1.size() - 1 - i]) return false;
        }
        return true;
    }

    string add(const string &s1, const string &s2) {
        char buf[2010] = {0};
        int i = 2000;
        int iter1 = s1.size() - 1;
        int iter2 = s2.size() - 1;
        int c = 0;
        while (iter1 >= 0 || iter2 >= 0) {
            int c1, c2;
            c1 = iter1 < 0 ? 0 : s1[iter1] - '0';
            c2 = iter2 < 0 ? 0 : s2[iter2] - '0';
            int ss = c1 + c2 + c;
            buf[i--] = ss % 10 + '0';
            c = ss / 10;

            iter1--, iter2--;
        }

        if (c != 0) {
            buf[i--] = c + '0';
        }
        string ss = buf + i + 1;
        return ss;
    }

    int main() {
        string s;
        cin >> s;
        bool ok = false;
        for (int i = 0; i < 10; i++) {
            if (isPalindrome(s)) {
                cout << s << " is a palindromic number." << endl;
                ok = true;
                break;
            }
            string s1 = s;
            reverse(s1.begin(), s1.end());
            auto addans = add(s, s1);
            cout << s << " + " << s1 << " = " << addans << endl;
            s = addans;
        }

        if (!ok) {
            cout << "Not found in 10 iterations." << endl;
        }
        return 0;
    }
}
