//
// Created by neild47 on 18-7-4.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

namespace pat1079 {
    int N;
    double P, r;

    int suppliers[100010];
    int dis[100010];

    int getDis(int u) {
        if (u == 0) return 0;
        if (dis[u] != -1) return dis[u];
        dis[u] = getDis(suppliers[u]) + 1;
        return dis[u];
    }

    int main() {
        fill(dis, dis + 100010, -1);
        cin >> N >> P >> r;
        r *= 0.01;
        vector<pair<int, int>> retailers;
        retailers.reserve(N);
        for (int i = 0; i < N; i++) {
            int k, v;
            scanf("%d", &k);
            if (k == 0) {
                scanf("%d", &v);
                retailers.emplace_back(i, v);
                continue;
            }
            for (int j = 0; j < k; j++) {
                scanf("%d", &v);
                suppliers[v] = i;
            }
        }

        double sumMoney = 0;
        double q = (1 + r);
        for (auto &retailer:retailers) {
            int u = retailer.first;
            double initMoney = retailer.second * P;
            int dis = getDis(u);
            sumMoney += initMoney * pow(q, dis);
        }
        printf("%.1f", sumMoney);
        return 0;
    }
}
