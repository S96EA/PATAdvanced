//
// Created by neild47 on 18-6-12.
//
#include <iostream>
#include <vector>

using namespace std;

namespace pat1043 {
    struct node {
        int value = 0;
        node *left = nullptr, *right = nullptr;

        node() {}
    };

    node *tree;
    vector<int> walkPath, rowPreOrder;


    void insert(node *&root, int value) {
        if (value < root->value) {
            if (root->left == nullptr) {
                root->left = new node;
                root->left->value = value;
            } else {
                insert(root->left, value);
            }
        } else {
            if (root->right == nullptr) {
                root->right = new node;
                root->right->value = value;
            } else {
                insert(root->right, value);
            }
        }
    }

    node *createTree(int n) {
        auto *root = new node;
        cin >> root->value;
        rowPreOrder.push_back(root->value);
        for (int i = 1; i < n; i++) {
            int value;
            cin >> value;
            rowPreOrder.push_back(value);
            insert(root, value);
        }
        return root;
    }

    void postOrderWalk(node *nd) {
        if (nd == nullptr) return;
        postOrderWalk(nd->left);
        postOrderWalk(nd->right);
        walkPath.push_back(nd->value);
    }

    void preOrderWalk(node *nd) {
        if (nd == nullptr) return;
        walkPath.push_back(nd->value);
        preOrderWalk(nd->left);
        preOrderWalk(nd->right);
    }

    void magicPreOrderWalk(node *nd) {
        if (nd == nullptr) return;
        walkPath.push_back(nd->value);
        magicPreOrderWalk(nd->right);
        magicPreOrderWalk(nd->left);
    }

    void magicPostOrderWalk(node *nd) {
        if (nd == nullptr) return;
        magicPostOrderWalk(nd->right);
        magicPostOrderWalk(nd->left);
        walkPath.push_back(nd->value);
    }

    int main() {
        int n;
        cin >> n;
        tree = createTree(n);
        walkPath.clear();
        preOrderWalk(tree);
        if (equal(walkPath.begin(), walkPath.end(), rowPreOrder.begin())) {
            cout << "YES" << endl;
            walkPath.clear();
            postOrderWalk(tree);
            for (int i = 0; i < walkPath.size(); ++i) {
                if (i != 0) cout << " ";
                cout << walkPath[i];
            }
        } else {
            walkPath.clear();
            magicPreOrderWalk(tree);
            if (equal(walkPath.begin(), walkPath.end(), rowPreOrder.begin())) {
                cout << "YES" << endl;
                walkPath.clear();
                magicPostOrderWalk(tree);
                for (int i = 0; i < walkPath.size(); ++i) {
                    if (i != 0) cout << " ";
                    cout << walkPath[i];
                }
            } else {
                cout << "NO" << endl;
            }
        }
        return 0;
    }
}


//部分关于将二叉树的数组描述转变成二叉树的算法
namespace orderArrToTree {

    struct Node {
        int value;
        Node *left, *right;

        Node() : value(0), left(nullptr), right(nullptr) {}
    };

    Node *preOrderToTree(const vector<int> &preOrderArr, int lo, int hi) {
        if (lo >= hi) return nullptr;
        auto node = new Node;
        node->value = preOrderArr[lo];
        int leftHi = lo + 1;
        while (leftHi < hi && preOrderArr[leftHi] < node->value) { leftHi++; }
        node->left = preOrderToTree(preOrderArr, lo + 1, leftHi);
        int rightHi = min(leftHi + 1, hi);
        while (rightHi < hi && preOrderArr[rightHi] >= node->value) { rightHi++; }
        node->right = preOrderToTree(preOrderArr, leftHi, rightHi);
        return node;
    }

    Node *postOrderToTree(const vector<int> &postOrderArr, int lo, int hi) {
        if (lo >= hi) return nullptr;
        auto node = new Node;
        node->value = postOrderArr[hi - 1];
        int leftHi = lo;
        while (leftHi < hi - 1 && postOrderArr[leftHi] < node->value) { leftHi++; }
        node->left = postOrderToTree(postOrderArr, lo, leftHi);
        node->right = postOrderToTree(postOrderArr, leftHi, hi - 1);
        return node;
    }

    void preOrderWalk(Node *node) {
        if (node == nullptr) return;
        cout << node->value << " ";
        preOrderWalk(node->left);
        preOrderWalk(node->right);
    }

    void postOrderWalk(Node *node) {
        if (node == nullptr) return;
        postOrderWalk(node->left);
        postOrderWalk(node->right);
        cout << node->value << " ";
    }


    void innerOrderWalk(Node *node) {
        if (node == nullptr) return;
        innerOrderWalk(node->left);
        cout << node->value << " ";
        innerOrderWalk(node->right);
    }


    int main() {
        int n;
        cin >> n;
        vector<int> orderTree(n);
        for (int i = 0; i < n; ++i) {
            cin >> orderTree[i];
        }
        auto tree = postOrderToTree(orderTree, 0, orderTree.size());
        preOrderWalk(tree);
        cout << endl;
        innerOrderWalk(tree);
        cout << endl;
        postOrderWalk(tree);
        return 0;
    }
}
