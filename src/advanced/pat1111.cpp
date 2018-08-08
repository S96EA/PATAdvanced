//
// Created by neild47 on 18-7-30.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

namespace pat1111 {

    const int INF = 99999999;

    int graph[510][510][2];
    int N, M;
    int S, D;

    bool vis[510];
    int dis[510];

    vector<int> prevPaths[510];
    int tmpCost, bestCost = INF;
    vector<int> bestPaths, tmpPaths;

    void dfs(int curr, int p) {
        if (curr == S) {
            if (tmpCost < bestCost) {
                bestPaths = tmpPaths;
                bestCost = tmpCost;
            }
            return;
        }

        for (auto u:prevPaths[curr]) {
            if (p) {
                tmpCost += graph[u][curr][1];
            } else {
                tmpCost++;
            }
            tmpPaths.push_back(u);
            dfs(u, p);
            tmpPaths.pop_back();
            if (p) {
                tmpCost -= graph[u][curr][1];
            } else {
                tmpCost--;
            }
        }
    }

    void printPath(const vector<int> &p) {
        for (int i = 0; i < p.size(); i++) {
            if (i != 0) printf(" -> ");
            printf("%d", p[i]);
        }
    }

    int main() {
        fill(&graph[0][0][0], &graph[510][0][0], INF);

        cin >> N >> M;
        for (int i = 0; i < M; i++) {
            int u, v, oneway, d, t;
            scanf("%d%d%d%d%d", &u, &v, &oneway, &d, &t);
            if (oneway) {
                graph[u][v][0] = d;
                graph[u][v][1] = t;
            } else {
                graph[u][v][0] = graph[v][u][0] = d;
                graph[u][v][1] = graph[v][u][1] = t;
            }
        }

        cin >> S >> D;
        vector<int> bestP[2];
        int costP[2];
        for (int p = 0; p <= 1; p++) {
            fill(dis, dis + N, INF);
            fill(vis, vis + N, false);
            bestCost = INF;
            tmpCost = 0;
            tmpPaths.clear();
            bestPaths.clear();
            for (int i = 0; i < N; i++) {
                prevPaths[i].clear();
            }
            dis[S] = 0;
            for (int i = 0; i < N; i++) {
                int u = -1, minD = INF;
                for (int j = 0; j < N; j++) {
                    if (!vis[j] && dis[j] < minD) {
                        minD = dis[j];
                        u = j;
                    }
                }

                if (u == -1 || minD == INF) break;
                vis[u] = true;

                for (int j = 0; j < N; j++) {
                    if (!vis[j]) {
                        if (dis[j] > dis[u] + graph[u][j][p]) {
                            prevPaths[j].clear();
                            prevPaths[j].push_back(u);
                            dis[j] = dis[u] + graph[u][j][p];
                        } else if (dis[j] == dis[u] + graph[u][j][p]) {
                            prevPaths[j].push_back(u);
                        }
                    }
                }
            }

            dfs(D, 1 - p);
            reverse(bestPaths.begin(), bestPaths.end());
            bestPaths.push_back(D);
            bestP[p] = bestPaths;
            costP[p] = dis[D];
        }
        if (bestP[0] == bestP[1]) {
            printf("Distance = %d; Time = %d: ", costP[0], costP[1]);
            printPath(bestP[0]);
        } else {
            printf("Distance = %d: ", costP[0]);
            printPath(bestP[0]);
            printf("\nTime = %d: ", costP[1]);
            printPath(bestP[1]);
        }
        return 0;
    }
}
