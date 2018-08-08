//
// Created by neild47 on 18-5-29.
//

#include <iostream>
#include <algorithm>


using namespace std;
namespace pat1009 {
#define N 1000
    void readP(double *p) {
        int k;
        cin >> k;
        for (int i = 0; i < k; i++) {
            int order;
            double eff;
            cin >> order >> eff;
            p[order] = eff;
        }
    }


    void mutiply(double *p1, double *p2, double *out) {
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= N; j++) {
                out[i + j] += p1[i] * p2[j];
            }
        }
    }

    double p1[1025];
    double p2[1025];
    double out[2050];

    int main() {
        readP(p1);
        readP(p2);
        mutiply(p1, p2, out);

        cout << count_if(out, out + 2050, [](double d) { return d != 0; });

        for (int i = 2000; i >= 0; i--) {
            if (out[i] != 0) {
                printf(" %d %.1f", i, out[i]);
            }
        }
        return 0;
    }
}
