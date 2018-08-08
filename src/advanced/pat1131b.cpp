//
// Created by neild47 on 18-8-3.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
namespace pat1131b {


    struct node {
        int station, line;
    };

    const int INF = 99999999;

    vector<node> graph[10010];
    bool vis[10010];
    int v1, v2;

    vector<node> tmpPath, bestPath;
    int minDis = INF, minTrans = INF;

    void printPath(const vector<node> &path) {
        cout << path.size() - 1 << endl;
        int start = 0, tail = 1;
        while (tail < path.size()) {
            while (tail + 1 < path.size() && path[tail].line == path[tail + 1].line) tail++;
            printf("Take Line#%d from %04d to %04d.\n", path[tail].line, path[start].station, path[tail].station);
            start = tail;
            tail = start + 1;
        }
    }

    void dfs(int curr, int line, int sumTrans) {
        if (curr == v2) {
            if (tmpPath.size() < minDis || (tmpPath.size() == minDis && sumTrans < minTrans)) {
                bestPath = tmpPath;
                minDis = bestPath.size();
                minTrans = sumTrans;
            }
            return;
        }


        for (auto u:graph[curr]) {
            if (vis[u.station]) { continue; }

            tmpPath.push_back(u);
            vis[u.station] = true;
            if (u.line != line) {
                dfs(u.station, u.line, sumTrans + 1);
            } else {
                dfs(u.station, u.line, sumTrans);
            }
            vis[u.station] = false;
            tmpPath.pop_back();
        }

    }


    int main() {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int k, v1, v2;
            scanf("%d%d", &k, &v1);
            for (int j = 1; j < k; j++) {
                scanf("%d", &v2);
                graph[v1].push_back(node{v2, i});
                graph[v2].push_back(node{v1, i});
                v1 = v2;
            }
        }

        int q;
        cin >> q;

        for (int i = 0; i < q; i++) {
            tmpPath.clear();
            bestPath.clear();
            fill(vis, vis + 10010, false);
            minDis = minTrans = INF;

            cin >> v1 >> v2;
            tmpPath.push_back(node{v1, -1});
            dfs(v1, -1, 0);

            printPath(bestPath);
        }

        return 0;
    }
}
