//
// Created by neild47 on 18-6-20.
//
#include <iostream>

using namespace std;

namespace pat1058 {
    int main() {
        long g1, s1, k1, g2, s2, k2;
        scanf("%ld.%ld.%ld %ld.%ld.%ld", &g1, &s1, &k1, &g2, &s2, &k2);
        long ko = s1 * 29 + g1 * 17 * 29 + k1 + s2 * 29 + g2 * 17 * 29 + k2;
        printf("%ld.%ld.%ld", ko / (17 * 29), ko / (29) % 17, ko % 29);
        return 0;
    }
}
