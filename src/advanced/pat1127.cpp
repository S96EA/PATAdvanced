//
// Created by neild47 on 18-8-2.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
namespace pat1127 {


    struct node {
        int value, depth;
        node *left, *right;
    };

    int n;
    vector<int> inorderSeq, postorderSeq;

    node *build(int in_lo, int in_hi, int post_lo, int post_hi) {
        if (in_lo > in_hi || post_lo > post_hi) return nullptr;
        if (in_lo == in_hi) {
            return new node{inorderSeq[in_lo]};
        }
        auto no = new node{postorderSeq[post_hi]};

        int mid = in_lo;

        while (inorderSeq[mid] != postorderSeq[post_hi]) {
            mid++;
        }
        int leftSize = mid - in_lo;
        no->left = build(in_lo, mid - 1, post_lo, post_lo + leftSize - 1);
        no->right = build(mid + 1, in_hi, post_lo + leftSize, post_hi - 1);

        return no;
    }

    void levelWalk(node *root) {
        queue<node *> bfsQueue;
        root->depth = 0;
        bfsQueue.push(root);

        vector<int> ans, levelAns;
        int oldDepth = 0;
        while (!bfsQueue.empty()) {
            auto u = bfsQueue.front();
            bfsQueue.pop();
            if (!u) continue;

            if (u->depth != oldDepth) {
                if (oldDepth % 2 == 0) {
                    reverse(levelAns.begin(), levelAns.end());
                }
                for (auto l:levelAns) {
                    ans.push_back(l);
                }
                levelAns.clear();
                oldDepth = u->depth;
            }

            levelAns.push_back(u->value);

            if (u->left) {
                u->left->depth = u->depth + 1;
                bfsQueue.push(u->left);
            }
            if (u->right) {
                u->right->depth = u->depth + 1;
                bfsQueue.push(u->right);
            }
        }

        if (oldDepth % 2 == 0) {
            reverse(levelAns.begin(), levelAns.end());
        }
        for (auto l:levelAns) {
            ans.push_back(l);
        }

        for (int i = 0; i < ans.size(); i++) {
            if (i) cout << " ";
            cout << ans[i];
        }
    }


    int main() {
        cin >> n;
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            inorderSeq.push_back(v);
        }

        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            postorderSeq.push_back(v);
        }

        node *root = build(0, n - 1, 0, n - 1);
        levelWalk(root);

        return 0;
    }
}
