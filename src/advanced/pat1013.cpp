//
// Created by neild47 on 18-6-1.
//
#include <iostream>

using namespace std;
namespace pat1013 {
    int neighbors[1001][1001];

    int checkNum;

    int color[1001] = {0};

    void dfs(int node) {
        color[node] = 1;
        for (int n = 1; n < 1001; n++) {
            if (neighbors[node][n] && !color[n]) {
                dfs(n);
            }
        }
    }

    int main() {
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 0; i < m; i++) {
            int s1, s2;
//            cin >> s1 >> s2;
            scanf("%d%d", &s1, &s2);
            neighbors[s1][s2] = 1;
            neighbors[s2][s1] = 1;
        }

        for (int i = 0; i < k; i++) {
            fill(color, color + 1001, 0);
            int dfsNum = 0;
            cin >> checkNum;
            color[checkNum] = 1;
            for (int node = 1; node <= n; node++) {
                if (!color[node]) {
                    dfs(node);
                    dfsNum++;
                }
            }
            cout << dfsNum - 1 << endl;
        }
        return 0;
    }
}

