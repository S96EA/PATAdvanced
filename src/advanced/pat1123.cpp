//
// Created by neild47 on 18-8-2.
//
#include <iostream>
#include <queue>

using namespace std;

namespace pat1123 {
    struct node {
        int value, height;
        node *left, *right;
    };

    int height(node *no) {
        if (no == nullptr) return 0;
        return max(height(no->left), height(no->right)) + 1;
    }

    node *rotateRight(node *no) {
        auto l = no->left;
        if (l == nullptr) return no;
        auto lr = l->right;
        l->right = no;
        no->left = lr;
        return l;
    }

    node *rotateLeft(node *no) {
        auto r = no->right;
        if (r == nullptr) return no;
        auto rl = r->left;
        r->left = no;
        no->right = rl;
        return r;
    }

    node *rotateLeftRight(node *no) {
        no->left = rotateLeft(no->left);
        return rotateRight(no);
    }

    node *rotateRightLeft(node *no) {
        no->right = rotateRight(no->right);
        return rotateLeft(no);
    }

    node *balance(node *no) {
        if (height(no->left) - height(no->right) > 1) {
            if (height(no->left->left) > height(no->left->right)) {
                no = rotateRight(no);
            } else {
                no = rotateLeftRight(no);
            }
        } else if (height(no->right) - height(no->left) > 1) {
            if (height(no->right->right) > height(no->right->left)) {
                no = rotateLeft(no);
            } else {
                no = rotateRightLeft(no);
            }
        }
        return no;
    }

    node *insert(int value, node *no) {
        if (no == nullptr) {
            return new node{value, 0};
        }
        if (value <= no->value) {
            no->left = insert(value, no->left);
        } else {
            no->right = insert(value, no->right);
        }

        return balance(no);
    }

    node *root;

    void inorderWalk(node *n) {
        if (!n) return;
        inorderWalk(n->left);
        cout << n->value << " ";
        inorderWalk(n->right);
    }

    vector<int> ans;

    bool isComp = true;

    int n, cnt;

    void levelOrderWalk(node *no) {
        queue<node *> bfsQueue;
        bfsQueue.push(no);
        while (!bfsQueue.empty()) {
            auto u = bfsQueue.front();
            bfsQueue.pop();
            if (u == nullptr) {
                if (cnt != n) {
                    isComp = false;
                }
                continue;
            }

            cnt++;
            ans.push_back(u->value);

            bfsQueue.push(u->left);
            bfsQueue.push(u->right);
        }
    }

    int main() {
        cin >> n;
        for (int i = 0; i < n; i++) {
            int v;
            scanf("%d", &v);
            root = insert(v, root);
        }

        levelOrderWalk(root);

        for (int i = 0; i < ans.size(); i++) {
            if (i) cout << " ";
            cout << ans[i];
        }
        cout << endl;

        printf(isComp ? "YES" : "NO");

        return 0;
    }
}
