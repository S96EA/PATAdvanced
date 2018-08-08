//
// Created by neild47 on 18-5-27.
//
#include <iostream>
#include <vector>

using namespace std;

namespace pat1004 {

    struct Node {
        vector<Node *> child;
    };


    Node nodes[128];

    int countLeaf[100];
    int maxDepth = 0;

    void dfs(Node *node, int depth) {
        if (depth > maxDepth) {
            maxDepth = depth;
        }
        if (node->child.empty()) {
            countLeaf[depth]++;
            return;
        }

        for (auto c:node->child) {
            dfs(c, depth + 1);
        }
    }

    int main() {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int id, k;
            cin >> id >> k;
            Node &parent = nodes[id];
            for (int j = 0; j < k; j++) {
                int cid;
                cin >> cid;
                parent.child.push_back(&nodes[cid]);
            }
        }

        dfs(&nodes[1], 0);
        for (int i = 0; i <= maxDepth; i++) {
            if (i != 0) {
                cout << " ";
            }
            cout << countLeaf[i];
        }
        return 0;
    }
}
