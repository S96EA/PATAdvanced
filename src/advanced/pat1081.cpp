//
// Created by neild47 on 18-7-10.
//
#include <iostream>

using namespace std;
namespace pat1081 {


    long long gcd(long long, long long);

    long long lcm(long long, long long);

    struct Number {
        long long a1, a2;

        void norm() {
            long long g = gcd(this->a1, this->a2);
            this->a1 /= g;
            this->a2 /= g;
        }

        Number &operator+=(const Number &number) {
            long long l = lcm(this->a2, number.a2);
            this->a1 = this->a1 * (l / this->a2) + number.a1 * (l / number.a2);
            this->a2 = l;
            norm();
            return *this;
        }
    };

    long long gcd(long long a1, long long a2) {
        if (a1 == 0 || a2 == 0) return 1;
        a1 = abs(a1);
        a2 = abs(a2);
        long long x = max(a1, a2);
        long long y = min(a1, a2);
        long long r = x % y;
        while (r) {
            x = y;
            y = r;
            r = x % y;
        }
        return y;
    }

    long long lcm(long long a1, long long a2) {
        return a1 * a2 / gcd(a1, a2);
    }

    int main() {
        int n;
        cin >> n;
        Number s{0, 1};
        for (int i = 0; i < n; i++) {
            Number number{};
            scanf("%lld/%lld", &number.a1, &number.a2);
            number.norm();
            s += number;
        }
        s.norm();
        if (s.a2 == 1) {
            cout << s.a1 << endl;
        } else {
            if (s.a1 / s.a2 != 0) {
                cout << s.a1 / s.a2;
                s.a1 = s.a1 % s.a2;
                if (s.a1 != 0) {
                    printf(" %lld/%lld\n", s.a1, s.a2);
                }
            } else {
                if (s.a1 == 0) {
                    cout << 0 << endl;
                } else {
                    printf("%lld/%lld\n", s.a1, s.a2);
                }
            }
        }
        return 0;
    }
}
