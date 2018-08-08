//
// Created by neild47 on 18-6-29.
//
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

namespace pat1071 {
    struct Mooncake {
        double amounts, prices;
    };

    bool comp(const Mooncake &m1, const Mooncake &m2) {
        return m1.prices > m2.prices;
    }

    int N;
    double D;

    int main() {
        cin >> N >> D;
        deque<Mooncake> mooncakes(N);
        double v;
        for (int i = 0; i < N; i++) {
            scanf("%lf", &mooncakes[i].amounts);
        }
        for (int i = 0; i < N; i++) {
            scanf("%lf", &mooncakes[i].prices);
            mooncakes[i].prices /= mooncakes[i].amounts;
        }

        sort(mooncakes.begin(), mooncakes.end(), comp);

        double sumProfits = 0;

        while (D > 0 && !mooncakes.empty()) {
            auto m = mooncakes.front();
            if (m.amounts >= D) {
                sumProfits += D * m.prices;
                break;
            } else {
                mooncakes.pop_front();
                sumProfits += m.amounts * m.prices;
                D -= m.amounts;
            }
        }

        printf("%.2f", sumProfits);
        return 0;
    }
}
