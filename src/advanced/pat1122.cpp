//
// Created by neild47 on 18-8-2.
//
#include <iostream>
#include <vector>

using namespace std;
namespace pat1122 {
    bool graph[210][210];
    bool vis[210];

    int N, M;

    int main() {
        cin >> N >> M;
        for (int i = 0; i < M; i++) {
            int v1, v2;
            scanf("%d%d", &v1, &v2);
            graph[v1][v2] = graph[v2][v1] = true;
        }

        int k;
        cin >> k;
        vector<int> tmpPath;
        for (int i = 0; i < k; i++) {
            tmpPath.clear();
            fill(vis, vis + 210, false);

            int l, v;
            scanf("%d", &l);
            for (int j = 0; j < l; j++) {
                scanf("%d", &v);
                tmpPath.push_back(v);
            }

            bool ok = true;
            if (l != N + 1 || tmpPath.back() != tmpPath.front()) {
                ok = false;
            } else {
                for (int j = 1; j < tmpPath.size(); j++) {
                    if (!graph[tmpPath[j - 1]][tmpPath[j]]) {
                        ok = false;
                        break;
                    } else {
                        vis[tmpPath[j]] = true;
                    }
                }
                if (ok) {
                    for (int j = 1; j <= N; j++) {
                        if (!vis[j]) {
                            ok = false;
                            break;
                        }
                    }
                }
            }
            printf(ok ? "YES\n" : "NO\n");
        }
        return 0;
    }
}
