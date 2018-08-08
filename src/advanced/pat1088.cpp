//
// Created by neild47 on 18-7-12.
//

#include <iostream>
#include <algorithm>

namespace pat1088 {
    using namespace std;

    long gcd(long a, long b) {
        if (a == 0 || b == 0) return 1;
        a = abs(a);
        b = abs(b);
        long x = max(a, b);
        long y = min(a, b);
        long r = x % y;
        while (r) {
            x = y;
            y = r;
            r = x % y;
        }
        return y;
    }

    long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }


    void norm(long &a1, long &a2) {
        long g = gcd(a1, a2);
        a1 /= g;
        a2 /= g;
    }


    void printNum(long a1, long a2) {
        norm(a1, a2);

        if (a2 < 0) {
            a2 = -a2;
            a1 = -a1;
        }
        if (a2 == 0) {
            printf("Inf");
            return;
        }
        bool havePa = (a1 < 0);
        if (havePa) {
            printf("(-");
            a1 = -a1;
        }
        long i = a1 / a2;
        a1 %= a2;
        if (i != 0) {
            printf("%ld", i);
        }
        if (a1 != 0) {
            if (i) {
                printf(" ");
            }
            printf("%ld/%ld", a1, a2);
        } else if (!i) {
            printf("0");
        }

        if (havePa) {
            printf(")");
        }
    }

    void printO(long a1, long a2, long b1, long b2, char opera) {
        printNum(a1, a2);
        printf(" %c ", opera);
        printNum(b1, b2);
        printf(" = ");
    }

    void add(long a1, long a2, long b1, long b2) {
        norm(a1, a2);
        norm(b1, b2);
        long c2 = a2 * b2;
        long c1 = a1 * b2 + a2 * b1;
        norm(c1, c2);
        printO(a1, a2, b1, b2, '+');
        printNum(c1, c2);
        cout << endl;
    }

    void sub(long a1, long a2, long b1, long b2) {
        norm(a1, a2);
        norm(b1, b2);
        long c2 = a2 * b2;
        long c1 = a1 * b2 - a2 * b1;
        norm(c1, c2);
        printO(a1, a2, b1, b2, '-');
        printNum(c1, c2);
        cout << endl;
    }

    void mul(long a1, long a2, long b1, long b2) {
        norm(a1, a2);
        norm(b1, b2);
        long c2 = a2 * b2;
        long c1 = a1 * b1;
        norm(c1, c2);
        printO(a1, a2, b1, b2, '*');
        printNum(c1, c2);
        cout << endl;
    }

    void div(long a1, long a2, long b1, long b2) {
        norm(a1, a2);
        norm(b1, b2);
        long c2 = a2 * b1;
        long c1 = a1 * b2;
        norm(c1, c2);
        printO(a1, a2, b1, b2, '/');
        printNum(c1, c2);
        cout << endl;
    }

    int main() {
        long a1, a2, b1, b2;
        scanf("%ld/%ld %ld/%ld", &a1, &a2, &b1, &b2);
        norm(a1, a2);
        norm(b1, b2);
        add(a1, a2, b1, b2);
        sub(a1, a2, b1, b2);
        mul(a1, a2, b1, b2);
        div(a1, a2, b1, b2);
        return 0;
    }
}
