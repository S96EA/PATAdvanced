//
// Created by neild47 on 18-6-29.
//
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

namespace pat1073 {

#define INF 99999999

    using namespace std;

    int N, M, K, D;

    int graph[1020][1020];
    bool vis[1020];
    int dis[1020];

    int getID(char *buf) {
        int d;
        if (buf[0] == 'G') {
            buf++;
            sscanf(buf, "%d", &d);
            return d + 1000;
        }
        sscanf(buf, "%d", &d);
        return d;
    }

    int main() {
        fill(graph[0], graph[1020], INF);
        cin >> N >> M >> K >> D;
        vector<int> ids;
        for (int i = 1; i <= N; i++) {
            ids.push_back(i);
        }
        for (int i = 1001; i <= 1000 + M; i++) {
            ids.push_back(i);
        }

        char buf1[10], buf2[10];

        for (int i = 0; i < K; i++) {
            int dis0;
            scanf("%s%s%d", buf1, buf2, &dis0);
            int id1 = getID(buf1);
            int id2 = getID(buf2);
            graph[id1][id2] = graph[id2][id1] = dis0;
        }

        vector<vector<double>> ans;

        for (int gas = 1; gas <= M; gas++) {
            fill(dis, dis + 1020, INF);
            fill(vis, vis + 1020, false);

            bool ok = true;
            int tmpGas = gas + 1000;
            //dijkstra
            dis[tmpGas] = 0;
            double totalDis = 0;
            int minAnsDis = INF;
            int cnt = 0;
            for (int i = 1; i <= N + M; i++) {
                int minDis = INF;
                int minIdx = -1;
                for (int j:ids) {
                    if (!vis[j] && dis[j] < minDis) {
                        minDis = dis[j];
                        minIdx = j;
                    }
                }

                if (minDis == INF) {
                    break;
                }

                vis[minIdx] = true;
                if (minIdx <= 1000) {//house
                    if (dis[minIdx] > D) {
                        ok = false;
                        break;
                    }
                    cnt++;
                    if (dis[minIdx] < minAnsDis) {
                        minAnsDis = dis[minIdx];
                    }
                    totalDis += dis[minIdx];
                }

                //relax
                for (int j : ids) {
                    if (!vis[j] && graph[minIdx][j] != INF) {
                        if (dis[minIdx] + graph[minIdx][j] < dis[j]) {
                            dis[j] = dis[minIdx] + graph[minIdx][j];
                        }
                    }
                }
            }
            if (ok && cnt == N) {
                totalDis /= N;
                ans.emplace_back(vector<double>{gas, minAnsDis, totalDis});
            }
        }

        if (ans.empty()) {
            cout << "No Solution" << endl;
        } else {
            sort(ans.begin(), ans.end(), [](vector<double> &v1, vector<double> &v2) {
                return v1[1] > v2[1];
            });
            auto e = ans.begin() + 1;
            while (e != ans.end() && (*e)[1] == ans[0][1]) {
                e++;
            }
            sort(ans.begin(), e, [](vector<double> &v1, vector<double> &v2) {
                if (v1[2] != v2[2]) { return v1[2] < v2[2]; }
                return v1[0] < v2[0];
            });

            auto &v = ans[0];
            printf("G%d\n", (int) v[0]);
            printf("%.1f %.1f\n", v[1], v[2]);
        }
        return 0;
    }
}
