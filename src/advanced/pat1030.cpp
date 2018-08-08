//
// Created by neild47 on 18-6-7.
//

#include <iostream>
#include <vector>


/*
 *
 * 一把过的，注意这里的邻接矩阵初始化为0，假设的是任意两个城市之间的距离不可能为0，因此在松弛的时候要判断两个城市之间是否是
 * 连通的。
 *
 * */

using namespace std;

namespace pat1030 {

#define INF  99999999

    int cities[510][510][2];
    int N, M, S, D;

    vector<int> path[510];
    int dis[510], vis[510];

    int minCost = INF, tmpCost, minDis, tmpDis;
    vector<int> minPath, tmpPath;

    void dfs(int u) {
        if (u == S) {
//            for (auto item = tmpPath.rbegin(); item != tmpPath.rend(); item++) {
//                cout << *item << " ";
//            }
//            cout << endl;
            if (tmpCost < minCost) {
                minPath = tmpPath;
                minCost = tmpCost;
                minDis = tmpDis;
            }
            return;
        }
        for (auto v:path[u]) {
            tmpPath.push_back(v);
            tmpCost += cities[u][v][1];
            tmpDis += cities[u][v][0];
            dfs(v);
            tmpDis -= cities[u][v][0];
            tmpCost -= cities[u][v][1];
            tmpPath.pop_back();
        }
    }

    int main() {
        fill(dis, dis + 510, INF);
        cin >> N >> M >> S >> D;
        for (int i = 0; i < M; i++) {
            int s1, s2, d, c;
            scanf("%d%d%d%d", &s1, &s2, &d, &c);
            cities[s1][s2][0] = cities[s2][s1][0] = d;
            cities[s1][s2][1] = cities[s2][s1][1] = c;
        }

        dis[S] = 0;
        for (int i = 0; i < N; i++) {
            int u = -1, minD = INF;
            for (int j = 0; j < N; j++) {
                if (!vis[j] && dis[j] < minD) {
                    u = j;
                    minD = dis[j];
                }
            }
            if (u == -1) break;
            vis[u] = 1;
            for (int j = 0; j < N; j++) {
                if (!vis[j] && cities[u][j][0] && cities[u][j][0] + dis[u] < dis[j]) {
                    dis[j] = cities[u][j][0] + dis[u];
                    path[j].clear();
                    path[j].push_back(u);
                } else if (cities[u][j][0] && cities[u][j][0] + dis[u] == dis[j]) {
                    path[j].push_back(u);
                }
            }
        }

        tmpPath.push_back(D);
        tmpCost = 0;
        dfs(D);

        for (auto item = minPath.rbegin(); item != minPath.rend(); item++) {
            cout << *item << " ";
        }
        cout << minDis << " " << minCost;
        return 0;
    }
}

