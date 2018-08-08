//
// Created by neild47 on 18-5-30.
//

#include <iostream>
#include <algorithm>

using namespace std;
namespace pat1010 {

    long stringToDec(const string &num, long long radix) {
        long long power = 1;
        long long dec = 0;
        for (int i = num.size() - 1; i >= 0; i--) {
            char c = num[i];
            if (isalpha(c)) {
                if (islower(c)) {
                    c = c - 'a' + 10;
                } else {
                    c = c - 'A' + 10;
                }
            } else {
                c = c - '0';
            }
            dec += c * power;
            power = power * radix;
        }
        return dec;
    }

    long long find_radix(string &number, long long n) {
        char mc = *max_element(number.begin(), number.end());
        long long lo = (isdigit(mc) ? mc - '0' : mc - 'a' + 10) + 1;
        long long hi = max(lo, n + 1);
        while (lo <= hi) {
            long long m = (lo + hi) / 2;
            long long cvt = stringToDec(number, m);
            if (cvt < 0 || cvt > n) {
                hi = m - 1;
            } else if (cvt == n) {
                return m;
            } else {
                lo = m + 1;
            }
        }
        return -1;
    }

    int main() {
        string n1, n2;
        long long tag, radix;
        cin >> n1 >> n2 >> tag >> radix;
        long long result = tag == 1 ? find_radix(n2, stringToDec(n1, radix)) : find_radix(n1, stringToDec(n2, radix));
        if (result == -1) {
            cout << "Impossible" << endl;
        } else {
            cout << result << endl;
        }
        return 0;
    }
}
