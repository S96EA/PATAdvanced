//
// Created by neild47 on 18-7-18.
//
#include <iostream>
#include <list>
#include <vector>
#include <queue>

namespace pat1099 {

    using namespace std;

    struct Node {
        int value, id;
        Node *left, *right;
    };

    struct NodeA {
        int value, left, right;
    };

    Node *root;
    list<int> values;
    int n;

    NodeA nodes[110];

    void createTree() {
        for (int i = 0; i < n; i++) {
            int l, r;
            scanf("%d%d", &l, &r);
            nodes[i].left = l;
            nodes[i].right = r;
        }
    }


    Node *createTree(int i) {
        if (i == -1) return nullptr;
        auto node = new Node{};
        node->id = i;
        node->left = createTree(nodes[i].left);
        node->right = createTree(nodes[i].right);
        return node;
    }

    void inorderWalk(Node *node) {
        if (node == nullptr) return;
        inorderWalk(node->left);
        node->value = values.front();
        values.pop_front();
        inorderWalk(node->right);
    }

    vector<int> ans;

    void levelorderWalk(Node *node) {
        queue<Node *> bfsQueue;
        bfsQueue.push(node);
        while (!bfsQueue.empty()) {
            auto u = bfsQueue.front();
            bfsQueue.pop();
            ans.push_back(u->value);
            if (u->left)
                bfsQueue.push(u->left);
            if (u->right)
                bfsQueue.push(u->right);
        }
    }

    int main() {
        cin >> n;
        createTree();

        root = createTree(0);

        for (int i = 0; i < n; i++) {
            int v;
            scanf("%d", &v);
            values.push_back(v);
        }
        values.sort();

        inorderWalk(root);

        levelorderWalk(root);

        for (int i = 0; i < ans.size(); i++) {
            if (i != 0) cout << " ";
            cout << ans[i];
        }
        cout << endl;

        return 0;
    }
}
