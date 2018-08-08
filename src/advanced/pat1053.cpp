//
// Created by neild47 on 18-6-14.
//
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
namespace pat1053 {
    struct Node {
        int id, weight, pre;
        long weightSum;

        Node(int id, int weight, long weightSum) : id(id), weight(weight), weightSum(weightSum) {}
    };

    int N, M;
    long S;

    vector<int> weights(110);

    vector<int> tree[110];

    vector<vector<int>> paths;

    int pre[110];

    bool pathComp(const vector<int> &p1, const vector<int> &p2) {
        auto iter_p1 = p1.rbegin(), iter_p2 = p2.rbegin();
        while (iter_p1 != p1.rend() && iter_p2 != p2.rend()) {
            if (*iter_p1 != *iter_p2) return *iter_p1 > *iter_p2;
            iter_p1++, iter_p2++;
        }
        return false;
    }

    void bfs() {
        queue<Node> bfsQueue;
        pre[0] = -1;
        bfsQueue.emplace(0, weights[0], weights[0]);
        while (!bfsQueue.empty()) {
            auto node = bfsQueue.front();
            bfsQueue.pop();
            if (node.weightSum > S) continue;
            if (tree[node.id].empty()) {//leaf
                if (node.weightSum == S) {
                    vector<int> tmpp;
                    while (node.id != -1) {
                        tmpp.push_back(weights[node.id]);
                        node.id = pre[node.id];
                    }
                    paths.push_back(tmpp);
                }
            } else {
                for (auto i :tree[node.id]) {
                    bfsQueue.emplace(i, weights[i], weights[i] + node.weightSum);
                    pre[i] = node.id;
                }
            }
        }

        sort(paths.begin(), paths.end(), pathComp);

        for (auto item:paths) {
            for (auto we = item.rbegin(); we != item.rend(); we++) {
                if (we != item.rbegin()) cout << " ";
                cout << *we;
            }
            cout << endl;
        }
    }

    int main() {
        cin >> N >> M >> S;
        for (int i = 0; i < N; i++) {
            scanf("%d", &weights[i]);
        }

        for (int i = 0; i < M; i++) {
            int node, k, c;
            scanf("%d%d", &node, &k);
            for (int j = 0; j < k; j++) {
                scanf("%d", &c);
                tree[node].push_back(c);
            }
        }

        bfs();

        return 0;
    }
}
