//
// Created by neild47 on 18-7-1.
//
#include <vector>
#include <iostream>
#include <algorithm>

namespace pat1074 {
    using namespace std;

    struct Node {
        int addr, value, next;
    };

    int Value[100010];
    int Next[100010];

    int main() {
        int head, N, K;
        cin >> head >> N >> K;
        for (int i = 0; i < N; i++) {
            int addr, vl, nxt;
            scanf("%d%d%d", &addr, &vl, &nxt);
            Value[addr] = vl;
            Next[addr] = nxt;
        }
        vector<Node> ans;
        int addr = head;
        while (addr != -1) {
            ans.push_back(Node{addr, Value[addr], Next[addr]});
            addr = Next[addr];
        }
        auto begin = ans.begin(), end = begin + K;
        while (end <= ans.end()) {
            reverse(begin, end);
            begin = end;
            end += K;
        }
        for (int i = 0; i < ans.size(); i++) {
            printf("%05d %d ", ans[i].addr, ans[i].value);
            if (i != ans.size() - 1) {
                printf("%05d\n", ans[i + 1].addr);
            } else {
                printf("-1\n");
            }
        }
        return 0;
    }
}
