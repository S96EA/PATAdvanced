//
// Created by neild47 on 18-7-20.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>

namespace pat1102 {
    using namespace std;

    struct node {
        int left, right, id;
    };

    int N, root;
    node tree[110];
    bool cnt[110];

    vector<int> ans;

    void printAns() {
        for (int i = 0; i < ans.size(); i++) {
            if (i != 0) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }

    void levelOrderWalk() {
        ans.clear();
        queue<node *> bfsQueue;
        bfsQueue.push(&tree[root]);
        while (!bfsQueue.empty()) {
            auto n = bfsQueue.front();
            bfsQueue.pop();
            ans.push_back(n->id);

            if (n->right != -1) {
                bfsQueue.push(&tree[n->right]);
            }
            if (n->left != -1) {
                bfsQueue.push(&tree[n->left]);
            }
        }
        printAns();
        ans.clear();
    }

    void inOrderWalk(int curr) {
        if (curr == -1) return;
        auto n = tree[curr];
        inOrderWalk(n.right);
        ans.push_back(n.id);
        inOrderWalk(n.left);
    }

    void inOrderWalk() {
        ans.clear();
        inOrderWalk(root);
        printAns();
        ans.clear();
    }


    int main() {
        cin >> N;
        string s;
        for (int i = 0; i < N; i++) {
            tree[i].id = i;
            cin >> s;
            if (s[0] == '-') {
                tree[i].left = -1;
            } else {
                int v = stoi(s);
                cnt[v] = true;
                tree[i].left = v;
            }

            cin >> s;
            if (s[0] == '-') {
                tree[i].right = -1;
            } else {
                int v = stoi(s);
                cnt[v] = true;
                tree[i].right = v;
            }
        }


        root = find(cnt, cnt + N, false) - cnt;

        levelOrderWalk();
        inOrderWalk();
        return 0;
    }
}
