//
// Created by neild47 on 18-7-1.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

namespace pat1076 {
    vector<int> followers[1010];
    int N, L;

    struct Node {
        int u, level;
    };
    bool visited[1010];

    int bfs(int startNode) {
        fill(visited, visited + 1010, false);
        queue<Node> bfsQueue;
        bfsQueue.push(Node{startNode, 0});
        int cnt = 0;
        visited[startNode] = true;

        while (!bfsQueue.empty()) {
            auto u = bfsQueue.front();
            bfsQueue.pop();
            for (auto v:followers[u.u]) {
                if (!visited[v] && u.level < L) {
                    visited[v] = true;
                    bfsQueue.push(Node{v, u.level + 1});
                    cnt++;
                }
            }
        }
        return cnt;
    }

    int main() {
        cin >> N >> L;
        for (int i = 1; i <= N; i++) {
            int k, v;
            scanf("%d", &k);
            for (int j = 0; j < k; j++) {
                scanf("%d", &v);
                followers[v].push_back(i);
            }
        }

        int k, v;
        scanf("%d", &k);
        for (int i = 0; i < k; i++) {
            scanf("%d", &v);
            cout << bfs(v) << endl;
        }

        return 0;
    }
}
