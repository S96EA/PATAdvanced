//
// Created by neild47 on 18-8-3.
//
#include <iostream>
#include <vector>

using namespace std;
namespace pat1130 {
    struct node {
        string value;
        int left, right;
    };

    node tree[50];
    bool vis[50];
    vector<string> ans;

    void inOrderWalk(int curr) {
        if (curr == -1) return;
        if (tree[curr].left == -1 && tree[curr].right == -1) {
            ans.push_back(tree[curr].value);
        } else {
            ans.emplace_back("(");
            inOrderWalk(tree[curr].left);
            ans.emplace_back(tree[curr].value);
            inOrderWalk(tree[curr].right);
            ans.emplace_back(")");
        }
    }

    int main() {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            string s;
            int left, right;
            cin >> s >> left >> right;

            if (left != -1) vis[left] = true;
            if (right != -1) vis[right] = true;

            tree[i].value = s;
            tree[i].left = left;
            tree[i].right = right;
        }

        int root = -1;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                root = i;
                break;
            }
        }

        inOrderWalk(root);
        int start = 0;
        if (ans[0] == "(") {
            ans.pop_back();
            start = 1;
        }
        for (int i = start; i < ans.size(); i++) {
            cout << ans[i];
        }

        return 0;
    }
}
