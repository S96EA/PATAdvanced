//
// Created by neild47 on 18-7-31.
//
#include <iostream>
#include <map>
#include <queue>

using namespace std;
namespace pat1115 {


    struct node {
        int value;
        int level;
        node *left, *right;
    };

    node *root;

    void insert0(int v, node *&node1) {
        if (node1 == nullptr) {
            node1 = new node{};
            node1->value = v;
            return;
        }
        if (v <= node1->value) {
            insert0(v, node1->left);
        } else {
            insert0(v, node1->right);
        }
    }

    int main() {
        int n, v;
        cin >> n;
        for (int i = 0; i < n; i++) {
            scanf("%d", &v);
            insert0(v, root);
        }

        queue<node *> bfsQueue;
        bfsQueue.push(root);
        map<int, int> levelCnt;

        while (!bfsQueue.empty()) {
            auto u = bfsQueue.front();
            bfsQueue.pop();

            levelCnt[u->level]++;

            if (u->left) {
                u->left->level = u->level + 1;
                bfsQueue.push(u->left);
            }
            if (u->right) {
                u->right->level = u->level + 1;
                bfsQueue.push(u->right);
            }
        }

        auto lc = levelCnt.rbegin();
        int n1 = lc->second, n2;
        lc++;
        if (lc == levelCnt.rend()) {
            n2 = 0;
        } else {
            n2 = lc->second;
        }

        printf("%d + %d = %d", n1, n2, n1 + n2);
        return 0;
    }
}
