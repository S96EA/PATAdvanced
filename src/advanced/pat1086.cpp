//
// Created by neild47 on 18-7-11.
//
#include <iostream>
#include <vector>

using namespace std;
namespace pat1086 {
    struct Node {
        int value;
        Node *left, *right;
    };

    int n, cnt = 0;
    vector<int> ans;

    void insert(Node *&node) {
        if (cnt == n) return;
        string cmd;
        cin >> cmd;
        if (cmd[1] == 'u') {//push
            int v;
            cin >> v;
            cnt++;
            node->left = new Node{v};
            insert(node->left);
            if (cnt == n) return;
            cin >> cmd;
            if (cmd[1] == 'u') {
                cin >> v;
                cnt++;
                node->right = new Node{v};
                insert(node->right);
            }
        } else {//pop
            if (cnt == n) return;
            cin >> cmd;
            if (cmd[1] == 'u') {
                int v;
                cin >> v;
                cnt++;
                node->right = new Node{v};
                insert(node->right);
            }
        }
    }

    void postOrder(Node *node) {
        if (node == nullptr) return;
        postOrder(node->left);
        postOrder(node->right);
        ans.push_back(node->value);
    }

    int main() {
        cin >> n;
        string cmd;
        int v;
        cin >> cmd >> v;
        auto node = new Node{v};
        cnt = 1;
        insert(node);
        postOrder(node);

        for (int i = 0; i < ans.size(); i++) {
            if (i != 0) printf(" ");
            printf("%d", ans[i]);
        }
        return 0;
    }
}
