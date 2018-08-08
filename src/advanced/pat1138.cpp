//
// Created by neild47 on 18-8-6.
//
#include <iostream>
#include <vector>

using namespace std;

namespace pat1138 {

    vector<int> preOrder, inOrder;

    bool ok = false;

    void build(int pre_lo, int pre_hi, int in_lo, int in_hi) {
        if (ok) return;
        if (pre_lo > pre_hi) return;
        if (pre_lo == pre_hi) {
            ok = true;
            cout << preOrder[pre_hi] << endl;
            return;
        }

        int root = preOrder[pre_lo];
        int mid = in_lo;
        while (inOrder[mid] != root) mid++;
        int leftSize = mid - in_lo;
        build(pre_lo + 1, pre_lo + leftSize, in_lo, mid - 1);
        build(pre_lo + leftSize + 1, pre_hi, mid + 1, in_hi);
    }

    int main() {
        int N, v;
        cin >> N;

        for (int i = 0; i < N; i++) {
            scanf("%d", &v);
            preOrder.push_back(v);
        }
        for (int i = 0; i < N; i++) {
            scanf("%d", &v);
            inOrder.push_back(v);
        }

        build(0, N - 1, 0, N - 1);
        return 0;
    }
}
