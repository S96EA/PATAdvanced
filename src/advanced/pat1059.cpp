//
// Created by neild47 on 18-6-20.
//

#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>

namespace pat1059 {

    using namespace std;

#define MAXN 100010

    bool su[MAXN];

    void getSu() {
        su[0] = su[1] = false;
        for (int i = 2; i < MAXN; i++) {
            if (su[i]) {
                int iter = i + i;
                while (iter < MAXN) {
                    su[iter] = false;
                    iter += i;
                }
            }
        }
    }

    bool isPrime(long num) {
        int sqrt_num = sqrt(num);
        for (int i = 2; i < sqrt_num; i++) {
            if (num % i) return false;
        }
        return true;
    }

    int main() {
        fill(su, su + MAXN, true);
        getSu();
        long num;
        cin >> num;
        cout << num << "=";
        if (isPrime(num)) {
            cout << num;
            return 0;
        }

        map<int, int> primeToCount;
        for (int i = 2; i < MAXN; i++) {
            if (su[i]) {
                while (num % i == 0) {
                    primeToCount[i]++;
                    num /= i;
                }
            }
            if (num == 1) break;
        }

        int c = 0;
        for (auto item:primeToCount) {
            if (c != 0) cout << "*";
            cout << item.first;
            if (item.second > 1) {
                cout << "^" << item.second;
            }
            c++;
        }

        return 0;
    }

}
