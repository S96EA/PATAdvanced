//
// Created by neild47 on 18-7-30.
//
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

namespace pat1110 {

    struct node {
        int idx, left, right;
    };

    node tree[110];
    bool idx[110];

    int main() {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string sl, sr;
            cin >> sl >> sr;
            tree[i].left = sl[0] == '-' ? -1 : stoi(sl.data());
            tree[i].right = sr[0] == '-' ? -1 : stoi(sr.data());
            tree[i].idx = i;
        }

        for (int i = 0; i < n; i++) {
            if (tree[i].left != -1) idx[tree[i].left] = true;
            if (tree[i].right != -1) idx[tree[i].right] = true;
        }

        int root = -1;
        for (int i = 0; i < n; i++) {
            if (!idx[i]) {
                if (tree[i].left != -1 || tree[i].right != -1) {
                    root = i;
                }
            }
        }

        queue<node> bfsQ;
        bfsQ.push(tree[root]);
        int lastN = -1;
        bool isEnd = false;
        bool isComp = true;
        while (!bfsQ.empty()) {
            node u = bfsQ.front();
            bfsQ.pop();

            lastN = u.idx;

            if (u.left != -1) {
                if (isEnd) isComp = false;
                bfsQ.push(tree[u.left]);
            } else {
                isEnd = true;
            }

            if (u.right != -1) {
                if (isEnd) isComp = false;
                bfsQ.push(tree[u.right]);
            } else {
                isEnd = true;
            }
        }


        if (isComp) {
            cout << "YES " << lastN << endl;
        } else {
            cout << "NO " << root << endl;
        }
        return 0;
    }
}
