//
// Created by neild47 on 18-8-8.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
namespace pat1147 {
    vector<int> tree;

    int cnt = 0;

    void postOrderWalk(int curr) {
        if (curr >= tree.size()) return;
        postOrderWalk(curr * 2 + 1);
        postOrderWalk(curr * 2 + 2);
        if (cnt) printf(" ");
        printf("%d", tree[curr]);
        cnt++;
    }

    int main() {
        int M, N;
        cin >> M >> N;
        tree.resize(N);

        for (int i = 0; i < M; i++) {
            fill(tree.begin(), tree.end(), -1);
            for (int j = 0; j < N; j++) {
                scanf("%d", &tree[j]);
            }
            bool isHeap = false;
            if (is_heap(tree.begin(), tree.end(), std::less<int>())) {
                printf("Max Heap\n");
                isHeap = true;
            }
            if (is_heap(tree.begin(), tree.end(), std::greater<int>())) {
                printf("Min Heap\n");
                isHeap = true;
            }
            if (!isHeap) {
                printf("Not Heap\n");
            }

            cnt = 0;
            postOrderWalk(0);
            printf("\n");
        }
        return 0;
    }
}
