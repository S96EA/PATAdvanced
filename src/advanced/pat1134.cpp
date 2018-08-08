//
// Created by neild47 on 18-8-4.
//
#include <iostream>
#include <vector>
#include <map>

using namespace std;

namespace pat1134 {
    struct node {
        int u;
        bool vis;
    };

    vector<int> graph0[10010];
    bool vis[10010];
    const int SHIFT = 10010;

    int main() {
        int n, m;
        cin >> n >> m;
        map<int, int> edges;

        for (int i = 0; i < m; i++) {
            int v1, v2;
            scanf("%d%d", &v1, &v2);
            graph0[v1].push_back(v2);
            graph0[v2].push_back(v1);

            edges.emplace(SHIFT * v1 + v2, i);
            edges.emplace(SHIFT * v2 + v1, i);
        }

        int q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            int k, v;
            cin >> k;
            for (int j = 0; j < k; j++) {
                scanf("%d", &v);
                for (auto u:graph0[v]) {
                    vis[edges[SHIFT * u + v]] = true;
                }
            }
            bool ok = true;
            for (int j = 0; j < m; j++) {
                if (!vis[j]) {
                    ok = false;
                    break;
                }
            }
            printf(ok ? "Yes\n" : "No\n");
            fill(vis, vis + m, false);
        }
        return 0;
    }
}
