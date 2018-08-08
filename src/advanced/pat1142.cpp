//
// Created by neild47 on 18-8-7.
//
#include <iostream>
#include <vector>
#include <set>

using namespace std;

namespace pat1142 {
    vector<int> graph[210];

    int main() {
        int N, E, v1, v2;
        cin >> N >> E;
        for (int i = 0; i < E; i++) {
            scanf("%d%d", &v1, &v2);
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }

        int q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            int k, v, vis[210] = {0};
            cin >> k;
            set<int> vs;
            for (int j = 0; j < k; j++) {
                scanf("%d", &v);

                for (auto u:graph[v]) {
                    vis[u]++;
                }

                vs.insert(v);
            }
//        for (int j = 1; j <= N; j++) {
//            cout << vis[j] << " ";
//        }
//        cout << endl;

            bool ok = true;
            for (auto v0:vs) {
                if (vis[v0] != k - 1) {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                printf("Not a Clique\n");
                continue;
            }

            bool notMax = false;
            for (int j = 1; j <= N; j++) {
                if (!vs.count(j) && vis[j] == k) {
                    notMax = true;
                    break;
                }
            }

            if (notMax) {
                printf("Not Maximal\n");
            } else {
                printf("Yes\n");
            }
        }
        return 0;
    }
}
