//
// Created by neild47 on 18-8-3.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
namespace pat1131 {


    struct node {
        int line, station;
    };

    const int INF = 99999999;

    vector<node> graph[10010];
    int graph0[10010][10010];

    vector<int> prevPaths[10010];

    int dis[10010], vis[10010];

    int u, v;
    int transferCnt, minTransferCnt = INF;
    vector<int> minPath, tmpPath;

    void printPath(const vector<int> &p) {
        int s = 0, e = 1, line;
        while (e < p.size()) {
            line = graph0[p[s]][p[e]];
//        int l1, l2;
//        for (auto n:graph[p[s]]) {
//            if (n.station == p[e]) {
//                line = n.line;
//            }
//        }
//
//        for (auto n:graph[p[e]]) {
//            if (n.station == p[e - 1]) {
//                l1 = n.line;
//            }
//            if (n.station == p[e + 1]) {
//                l2 = n.line;
//            }
//        }
            while (e + 1 < p.size() && graph0[p[e - 1]][p[e]] == graph0[p[e + 1]][p[e]]) {
                e++;
            }
            printf("Take Line#%d from %04d to %04d.\n", line, p[s], p[e]);

            s = e;
            e = s + 1;
        }
    }

    int transferN(const vector<int> &p) {
        int cnt = 0;
        int s = 0, e = 1;
        while (e < p.size()) {
            while (e + 1 < p.size() && graph0[p[e - 1]][p[e]] == graph0[p[e + 1]][p[e]]) {
                e++;
            }
            s = e;
            e = s + 1;
            cnt++;
        }
        return cnt;
    }

    void dfs(int curr) {
        if (curr == u) {
            transferCnt = transferN(tmpPath);
            if (transferCnt < minTransferCnt) {
                minPath = tmpPath;
                minTransferCnt = transferCnt;
            }
            return;
        }

        for (auto pp:graph[curr]) {
            graph0[curr][pp.station] = graph0[pp.station][curr] = pp.line;
        }

        for (auto prevS:prevPaths[curr]) {
            tmpPath.push_back(prevS);
            dfs(prevS);
            tmpPath.pop_back();
        }

    }

    int main() {
        int n, totalStations = 0;
        cin >> n;
        set<int> stations;
        for (int i = 1; i <= n; i++) {
            int k, v1, v2;
            scanf("%d%d", &k, &v1);
            stations.insert(v1);
            totalStations += k;
            for (int j = 1; j < k; j++) {
                scanf("%d", &v2);
                graph[v1].push_back(node{i, v2});
                graph[v2].push_back(node{i, v1});
//            graph0[v1][v2] = graph0[v2][v1] = i;
                v1 = v2;
                stations.insert(v1);
            }
        }

        int q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            fill(dis, dis + 10010, INF);
            fill(vis, vis + 10010, false);
            minPath.clear();
            tmpPath.clear();
            minTransferCnt = INF, transferCnt = 0;

            cin >> u >> v;

            dis[u] = 0;
            for (int j = 0; j < totalStations; j++) {
                int idx = -1, mindis = INF;
                for (auto k:stations) {
                    if (!vis[k] && dis[k] < mindis) {
                        mindis = dis[k];
                        idx = k;
                    }
                }
                if (mindis == INF || idx == -1) break;

                vis[idx] = true;

                if (idx == v) break;

                for (auto &no:graph[idx]) {
                    int k = no.station;
                    if (!vis[k]) {
                        if (dis[idx] + 1 < dis[k]) {
                            dis[k] = dis[idx] + 1;
                            prevPaths[k].clear();
                            prevPaths[k].push_back(idx);
                        } else if (dis[idx] + 1 == dis[k]) {
                            prevPaths[k].push_back(idx);
                        }
                    }
                }
            }
            tmpPath.push_back(v);
            cout << dis[v] << endl;
            dfs(v);
            reverse(minPath.begin(), minPath.end());
            printPath(minPath);
        }

        return 0;
    }
}
