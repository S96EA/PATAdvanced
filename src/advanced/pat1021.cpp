//
// Created by neild47 on 18-6-4.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

namespace pat1021 {
    int numNodes;

    vector<int> nodes[10001];

    vector<int> deepNodes;

    bool visit[100001];

    int components = 0;

    int tmpMaxDepth = -1;
    int maxDepth = -1;

    void dfs(int v, int depth) {
        visit[v] = true;
        if (depth > tmpMaxDepth) {
            tmpMaxDepth = depth;
        }
        for (auto nei:nodes[v]) {
            if (!visit[nei]) {
                dfs(nei, depth + 1);
            }
        }
    }

    int main() {
        cin >> numNodes;
        for (int i = 0; i < numNodes - 1; i++) {
            int s1, s2;
            if (scanf("%d%d", &s1, &s2))
                return 0;
            nodes[s1].push_back(s2);
            nodes[s2].push_back(s1);
        }

        for (int i = 1; i <= numNodes; i++) {
            components = 0;
            tmpMaxDepth = -1;
            fill(visit, visit + numNodes + 10, false);

            dfs(i, 0);
            components++;
            for (int j = 1; j <= numNodes; j++) {
                if (!visit[j]) {
                    dfs(j, 0);
                    components++;
                }
            }
            if (components != 1) {
                cout << "Error: " << components << " components" << endl;
                break;
            } else {
                if (tmpMaxDepth > maxDepth) {
                    deepNodes.clear();
                    deepNodes.push_back(i);
                    maxDepth = tmpMaxDepth;
                } else if (tmpMaxDepth == maxDepth) {
                    deepNodes.push_back(i);
                }
            }
        }

        sort(deepNodes.begin(), deepNodes.end());

        for (int i = 0; i < (int) deepNodes.size(); i++) {
            cout << deepNodes[i] << endl;
        }
        return 0;
    }
}
