//
// Created by neild47 on 18-8-1.
//
#include <iostream>
#include <vector>

using namespace std;
namespace pat1119 {


    struct node {
        int value;
        node *left, *right;
    };


    vector<int> preOrderSeq, postOrderSeq;
    bool isUnique = true;

//[pre_lo,pre_hi], [post_lo, post_hi]
    node *build(int pre_lo, int pre_hi, int post_lo, int post_hi) {
        if (pre_lo > pre_hi || post_lo > post_hi) return nullptr;
        if (pre_lo == pre_hi) {
            auto no = new node{};
            no->value = preOrderSeq[pre_lo];
            return no;
        }

        auto root = new node{};
        root->value = preOrderSeq[pre_lo];
        int post_mid_delta = 0;
        while (postOrderSeq[post_lo + post_mid_delta] != preOrderSeq[pre_lo + 1]) {
            post_mid_delta++;
        }
        if (post_lo + post_mid_delta == post_hi - 1) {
            isUnique = false;
            root->left = build(pre_lo + 1, pre_hi, post_lo, post_hi - 1);
        } else {
            root->left = build(pre_lo + 1, pre_lo + 1 + post_mid_delta, post_lo, post_lo + post_mid_delta);
            root->right = build(pre_lo + 1 + post_mid_delta + 1, pre_hi, post_lo + post_mid_delta + 1, post_hi - 1);
        }
        return root;
    }

    vector<int> ans;

    void inorderWalk(node *no) {
        if (no == nullptr) {
            return;
        }

        inorderWalk(no->left);
        ans.push_back(no->value);
        inorderWalk(no->right);
    }

    int main() {
        int n, v;
        cin >> n;
        for (int i = 0; i < n; i++) {
            scanf("%d", &v);
            preOrderSeq.push_back(v);
        }

        for (int i = 0; i < n; i++) {
            scanf("%d", &v);
            postOrderSeq.push_back(v);
        }


        auto root = build(0, n - 1, 0, n - 1);
        inorderWalk(root);

        printf(isUnique ? "Yes" : "No");
        cout << endl;
        for (int i = 0; i < ans.size(); i++) {
            if (i) cout << " ";
            cout << ans[i];
        }
        cout << endl;
        return 0;
    }
}
