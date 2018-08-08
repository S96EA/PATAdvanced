//
// Created by neild47 on 18-6-28.
//
//
// Created by neild47 on 18-6-27.
//
#include <iostream>

namespace pat1067 {


    using namespace std;

    struct Node {
        int value;
        Node *left, *right;
        int height;

        Node() : value{}, left{}, right{}, height{} {}
    };

    int height(Node *node) {
        return node == nullptr ? -1 : node->height;
    }

    void updateHeight(Node *node) {
        if (node == nullptr) return;
        node->height = max(height(node->left), height(node->right)) + 1;
    }

    Node *rotateLeft(Node *node) {
        Node *rNode = node->right;
        Node *rlNode = node->right->left;
        rNode->left = node;
        node->right = rlNode;
        updateHeight(node);
        updateHeight(rNode);
        return rNode;
    }

    Node *rotateRight(Node *node) {
        Node *lNode = node->left;
        Node *lrNode = node->left->right;
        lNode->right = node;
        node->left = lrNode;
        updateHeight(node);
        updateHeight(lNode);
        return lNode;
    }

    Node *rotateLeftRight(Node *node) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    Node *rotateRightLeft(Node *node) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    Node *balance(Node *node) {
//    cout << node->value << " " << height(node) << " " << height(node->left) << " " << height(node->right) << endl;
        if (height(node->left) - height(node->right) > 1) {
            if (height(node->left->left) > height(node->left->right)) {//single rotate
//            cout << "rotate right: " << node->value << endl;
                return rotateRight(node);
            } else if (height(node->left->right) > height(node->left->left)) {//double rotate
//            cout << "rotate left right: " << node->value << endl;
                return rotateLeftRight(node);
            }
        } else if (height(node->right) - height(node->left) > 1) {
            if (height(node->right->right) > height(node->right->left)) {//single rotate
//            cout << "rotate left: " << node->value << endl;
                return rotateLeft(node);
            } else if (height(node->right->left) > height(node->right->right)) {//double rotate
//            cout << "rotate right left: " << node->value << endl;
                return rotateRightLeft(node);
            }
        }

        updateHeight(node);

        return node;
    }

    Node *insert(Node *node, int value) {
        if (node == nullptr) {
            node = new Node();
            node->value = value;
            return node;
        }
        if (value < node->value) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }

        return balance(node);
    }

    Node *root{};

    int main() {
        int n, v;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> v;
            root = insert(root, v);
        }
        cout << root->value << endl;
        return 0;
    }
}


