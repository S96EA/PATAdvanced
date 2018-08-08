//
// Created by neild47 on 18-8-4.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

namespace pat1135 {

    using namespace std;

    struct node {
        int value;
        node *left, *right;
    };

    bool cmp(int a, int b) {
        return abs(a) < abs(b);
    }

    vector<int> preOrderSeq, inOrderSeq;

    node *build(int pre_lo, int pre_hi, int in_lo, int in_hi) {
//    cout << pre_lo << " " << pre_hi << " " << in_lo << " " << in_hi << endl;
        if (pre_lo > pre_hi || in_lo > in_hi) return nullptr;
        if (pre_lo == pre_hi) {
            return new node{preOrderSeq[pre_lo]};
        }
        node *node0 = new node{preOrderSeq[pre_lo]};
        int mid = in_lo;
        while (inOrderSeq[mid] != preOrderSeq[pre_lo]) mid++;
//    cout << "=============" << mid << endl;
        int leftSize = mid - in_lo;
        node0->left = build(pre_lo + 1, pre_lo + leftSize, in_lo, mid - 1);
        node0->right = build(pre_lo + leftSize + 1, pre_hi, mid + 1, in_hi);
        return node0;
    }

    void levelWalk(node *root) {
        queue<node *> bfsQueue;
        bfsQueue.push(root);
        while (!bfsQueue.empty()) {
            auto u = bfsQueue.front();
            bfsQueue.pop();
            if (!u) continue;
            cout << u->value << " ";
            bfsQueue.push(u->left);
            bfsQueue.push(u->right);
        }
    }

    bool isOk = true;
    int blackCnt = -1;

    void isRbTree(node *node1, int tmpBlackCnt) {
        if (node1 == nullptr) {
            if (blackCnt == -1) {
                blackCnt = tmpBlackCnt;
            } else if (blackCnt != tmpBlackCnt) {
                isOk = false;
            }
            return;
        }

        if (node1->value < 0) {
            if (node1->left && node1->left->value < 0) {
                isOk = false;
            }
            if (node1->right && node1->right->value < 0) {
                isOk = false;
            }
        }

        if (node1->value > 0) {
            isRbTree(node1->left, tmpBlackCnt + 1);
            isRbTree(node1->right, tmpBlackCnt + 1);
        } else {
            isRbTree(node1->left, tmpBlackCnt);
            isRbTree(node1->right, tmpBlackCnt);
        }
    }

    int main() {
        int k;
        cin >> k;

        for (int i = 0; i < k; i++) {
            preOrderSeq.clear();
            inOrderSeq.clear();

            int n, v;
            cin >> n;
            for (int j = 0; j < n; j++) {
                cin >> v;
                preOrderSeq.push_back(v);
            }
            inOrderSeq = preOrderSeq;
            sort(inOrderSeq.begin(), inOrderSeq.end(), cmp);
//        for (auto item:inOrderSeq) {
//            cout << item << " ";
//        }
//        cout << endl;

            node *root = nullptr;
            root = build(0, preOrderSeq.size() - 1, 0, inOrderSeq.size() - 1);
//        levelWalk(root);
//        cout << endl;
            if (root->value < 0) {
                printf("No\n");
            } else {
                isOk = true;
                blackCnt = -1;
                isRbTree(root, 0);
                printf(isOk ? "Yes\n" : "No\n");
            }
        }


        return 0;
    }
}
