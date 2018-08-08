//
// Created by neild47 on 18-6-14.
//

#include <iostream>
#include <stack>
#include <queue>

using namespace std;
namespace pat1051 {
    int main() {
        vector<int> popQueue;
        int M, N, K, v;
        cin >> M >> N >> K;
        for (int t = 0; t < K; t++) {
            stack<int> popStack;
            popQueue.clear();
            for (int i = 0; i < N; i++) {
                scanf("%d", &v);
                popQueue.push_back(v);
            }
            int i = 0, n = 1;
            bool ok = true;
            while (i < popQueue.size()) {
                while (popStack.empty() || popStack.top() != popQueue[i] && popStack.size() < M) {
                    popStack.push(n++);
                }
                if (popStack.top() != popQueue[i]) {
                    ok = false;
                    break;
                }
                popStack.pop(), i++;
            }
            cout << (ok ? "YES" : "NO") << endl;
        }
        return 0;
    }
}
