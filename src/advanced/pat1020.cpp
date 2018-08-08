//
// Created by neild47 on 18-6-4.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

namespace pat1020 {
    using namespace std;

    struct Node {
        int value;
        Node *left;
        Node *right;
    };

    Node *newNode() {
        auto n = new Node;
        n->value = -1;
        n->left = nullptr;
        n->right = nullptr;
        return n;
    }


    int postorder[30];
    int inorder[30];

    int n;

    Node *createTree(int ps, int pe, int is, int ie) {
        if (ps > pe) return nullptr;

        if (ps == pe) {
            auto node = newNode();
            node->value = postorder[ps];
            return node;
        }

        auto node = newNode();
        node->value = postorder[pe];
        int inorderRootPos = find(inorder, inorder + n, postorder[pe]) - inorder;
        int leftSize = inorderRootPos - is;
        int rightSize = ie - inorderRootPos;
        if (leftSize > 0)
            node->left = createTree(ps, ps + leftSize - 1, is, is + leftSize - 1);

        if (rightSize > 0)
            node->right = createTree(ps + leftSize, pe - 1, inorderRootPos + 1, inorderRootPos + rightSize);

        return node;
    }

    void innoderWalk(Node *node) {
        if (node == nullptr) {
            return;
        }
        cout << node->value << endl;
    }


    int main() {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> postorder[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> inorder[i];
        }

        auto node = createTree(0, n - 1, 0, n - 1);

        vector<int> ans;
        queue<Node *> walkQueue;

        walkQueue.push(node);
        while (!walkQueue.empty()) {
            auto tmpn = walkQueue.front();
            walkQueue.pop();

            ans.push_back(tmpn->value);
            if (tmpn->left)
                walkQueue.push(tmpn->left);

            if (tmpn->right)
                walkQueue.push(tmpn->right);
        }

        for (int i = 0; i < ans.size(); i++) {
            if (i != 0) cout << " ";
            cout << ans[i];
        }
        cout << endl;

        return 0;
    }
}
