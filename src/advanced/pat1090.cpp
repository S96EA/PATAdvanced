//
// Created by neild47 on 18-7-12.
//

#include <iostream>
#include <algorithm>
#include <cmath>

namespace pat1090 {
    using namespace std;

    int parent[100010];
    int N, root;
    double P, R;
    int dis[100010];

    int dfs(int curr) {
        if (dis[curr] != -1) return dis[curr];
        if (curr == root) {
            return 0;
        }
        dis[curr] = dfs(parent[curr]) + 1;
        return dis[curr];
    }

    int main() {
        fill(dis, dis + 100010, -1);
        cin >> N >> P >> R;
        int v;
        for (int i = 0; i < N; i++) {
            scanf("%d", &v);
            parent[i] = v;
            if (v == -1) {
                root = i;
                dis[root] = 0;
            }
        }

        for (int i = 0; i < N; i++) {
            if (dis[i] == -1)
                dfs(i);
        }

        int maxDis = *max_element(dis, dis + N);
        int numMaxDis = count(dis, dis + N, maxDis);

        R = R / 100;
        printf("%.2f %d", P * pow(1 + R, maxDis), numMaxDis);
        return 0;
    }
}
