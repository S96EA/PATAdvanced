//
// Created by neild47 on 18-8-7.
//

#include <vector>
#include <iostream>
#include <vector>

namespace pat1143 {

    using namespace std;

    struct node {
        int value;
        node *left, *right;
    };

    void insert(int value, node *&node1) {
        if (node1 == nullptr) {
            node1 = new node{value};
            return;
        }
        if (value < node1->value) {
            insert(value, node1->left);
        } else {
            insert(value, node1->right);
        }
    }

    void preOrderWalk(node *node1) {
        if (node1 == nullptr) return;
        cout << node1->value << " ";
        preOrderWalk(node1->left);
        preOrderWalk(node1->right);
    }

    int v1, v2;

    bool findA = false, findB = false, AisAncOfB = false, BisAncOfA = false;
    node *anc = nullptr;

    vector<int> tmpPath;

    bool find(int value, node *node1) {
        if (node1 == nullptr) return false;
        tmpPath.push_back(node1->value);
        if (value == node1->value) return true;
        if (value < node1->value) {
            return find(value, node1->left);
        } else {
            return find(value, node1->right);
        }
    }

    void dfs(node *curr) {
        if (curr == nullptr) return;
        if (v1 < curr->value && v2 > curr->value || v1 > curr->value && v2 < curr->value) {
            anc = curr;
//        if (v1 < curr->value) {
//            findA = find(v1, curr->left);
//            findB = find(v2, curr->right);
//        } else {
//            findA = find(v1, curr->right);
//            findB = find(v2, curr->left);
//        }
            return;
        }

        if (v1 == curr->value) {
            AisAncOfB = true;
            findA = true;
            anc = curr;
//        findB = find(v2, v2 < v1 ? curr->left : curr->right);
            return;
        }

        if (v2 == curr->value) {
            BisAncOfA = true;
            findB = true;
            anc = curr;
//        findA = find(v1, v1 < v2 ? curr->left : curr->right);
            return;
        }

        if (v1 < curr->value) {
            dfs(curr->left);
        } else {
            dfs(curr->right);
        }
    }


    vector<int> preOrdeSeq;

    node *build(int pre_lo, int pre_hi) {
        if (pre_lo > pre_hi) return nullptr;
        auto node1 = new node{preOrdeSeq[pre_lo]};
        if (pre_lo == pre_hi) {
            return node1;
        }
        int root = preOrdeSeq[pre_lo];
        int right = pre_hi;
        while (right > pre_lo && preOrdeSeq[right] >= root) right--;
        node1->left = build(pre_lo + 1, right);
        node1->right = build(right + 1, pre_hi);
        return node1;
    }

    int main() {
        int M, N, v;
        scanf("%d%d", &M, &N);

        node *root = nullptr;
        for (int i = 0; i < N; i++) {
            scanf("%d", &v);
            preOrdeSeq.push_back(v);
        }

        root = build(0, N - 1);

        for (int i = 0; i < M; i++) {
            findA = findB = AisAncOfB = BisAncOfA = false;
            anc = nullptr;
            scanf("%d%d", &v1, &v2);
            tmpPath.clear();
            findA = find(v1, root);
            vector<int> pa = tmpPath;
            tmpPath.clear();
            findB = find(v2, root);
            vector<int> &pb = tmpPath;
            if (!findA && !findB) {
                printf("ERROR: %d and %d are not found.\n", v1, v2);
            } else if (!findA) {
                printf("ERROR: %d is not found.\n", v1);
            } else if (!findB) {
                printf("ERROR: %d is not found.\n", v2);
            } else {
//            dfs(root);
                int anc = 0;
                while (anc < pa.size() && anc < pb.size() && pa[anc] == pb[anc]) anc++;
                if (anc == pa.size()) {
                    AisAncOfB = true;
                } else if (anc == pb.size()) {
                    BisAncOfA = true;
                } else {
                    anc = pa[anc - 1];
                }
                if (AisAncOfB) {
                    printf("%d is an ancestor of %d.\n", v1, v2);
                } else if (BisAncOfA) {
                    printf("%d is an ancestor of %d.\n", v2, v1);
                } else {
                    printf("LCA of %d and %d is %d.\n", v1, v2, anc);
                }
            }
        }
        return 0;
    }
}
