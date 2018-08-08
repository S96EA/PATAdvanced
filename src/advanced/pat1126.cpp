//
// Created by neild47 on 18-8-2.
//
#include <iostream>

using namespace std;

namespace pat1126 {

    int degrees[510];
    bool graph[510][510];
    bool vis[510];

    int N, M;
    int tmpCnt = 0;

    void dfs(int curr) {
        vis[curr] = true;

        for (int i = 1; i <= N; i++) {
            if (!vis[i] && graph[i][curr]) {
                tmpCnt++;
                dfs(i);
            }
        }
    }

    int main() {
        cin >> N >> M;
        for (int i = 0; i < M; i++) {
            int v1, v2;
            scanf("%d%d", &v1, &v2);
            degrees[v1]++;
            degrees[v2]++;
            graph[v1][v2] = graph[v2][v1] = true;
        }

        int oddCount = 0;
        for (int i = 1; i <= N; i++) {
            if (i != 1) printf(" ");
            if (degrees[i] % 2) oddCount++;
            printf("%d", degrees[i]);
        }
        cout << endl;

        int dfscnt = 0;
        for (int i = 1; i <= N; i++) {
            if (!vis[i]) {
                tmpCnt = 0;
                dfs(i);
                if (tmpCnt) {
                    dfscnt++;
                }
            }
        }

        if (dfscnt > 1) {
            cout << "Non-Eulerian" << endl;
            return 0;
        }

        if (!oddCount) {
            cout << "Eulerian" << endl;
        } else if (oddCount == 2) {
            cout << "Semi-Eulerian" << endl;
        } else {
            cout << "Non-Eulerian" << endl;
        }
        return 0;
    }
}
