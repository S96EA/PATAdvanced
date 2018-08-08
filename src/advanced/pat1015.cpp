//
// Created by neild47 on 18-6-2.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
namespace pat1015 {

#define N 110000

    int isPrime[N];

    void checkPrime() {
        for (int i = 2; i < N; i++) {
            if (isPrime[i]) {
                int tmp = i + i;
                while (tmp < N) {
                    isPrime[tmp] = 0;
                    tmp += i;
                }
            }
        }
    }

    int reverseNum(int num, int d) {
        vector<int> newNum;
        while (num > 0) {
            newNum.push_back(num % d);
            num /= d;
        }
        int p = 1;
        int n = 0;
        while (!newNum.empty()) {
            n += p * newNum.back();
            newNum.pop_back();
            p *= d;
        }
        return n;
    }

    int main() {
        fill(isPrime, isPrime + N, 1);
        checkPrime();
        isPrime[0] = isPrime[1] = 0;
        int a, d;
        while (true) {
            cin >> a;
            if (a < 0) {
                break;
            }
            cin >> d;
            if (isPrime[a] && isPrime[reverseNum(a, d)]) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
        return 0;
    }
}
