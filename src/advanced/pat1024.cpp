//
// Created by neild47 on 18-6-5.
//
#include <iostream>
#include <algorithm>

using namespace std;
namespace pat1024 {
    string reverse(string s) {
        string ret = "";
        for (auto item = s.rbegin(); item != s.rend(); item++) {
            ret += *item;
        }
        return ret;
    }


    bool isPa(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    string add(string a1, string a2) {
        string s = "";
        auto iterA1 = a1.rbegin();
        auto iterA2 = a2.rbegin();
        int c = 0;
        while (iterA1 != a1.rend() && iterA2 != a2.rend()) {
            int n = (*iterA1 + *iterA2 - 2 * '0' + c);
            c = n / 10;
            n = n % 10;
            s = to_string(n) + s;
            iterA1++;
            iterA2++;
        }

        while (iterA1 != a1.rend()) {
            int n = (*iterA1 - '0' + c);
            c = n / 10;
            n = n % 10;
            s = to_string(n) + s;
            iterA1++;
        }
        while (iterA2 != a2.rend()) {
            int n = (*iterA2 - '0' + c);
            c = n / 10;
            n = n % 10;
            s = to_string(n) + s;
            iterA2++;
        }
        if (c != 0) {
            s = to_string(c) + s;
        }
        if (s.size() != 1) {
            auto noz = find_if(s.begin(), s.end(), [](const char c) { return c != '0'; });
            if (noz == s.end()) {
                return "0";
            } else {
                return s.substr(noz - s.begin());
            }
        }
        return s;
    }

    int main() {
        string num;
        long n;
        int k;
        cin >> n >> k;
        num = to_string(n);
        int i = 0;
        while (!isPa(num) && i < k) {
            num = add(num, reverse(num));
            i++;
        }
        cout << num << endl;
        cout << i << endl;
        return 0;
    }
}
