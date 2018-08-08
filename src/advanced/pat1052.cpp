//
// Created by neild47 on 18-6-14.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
namespace pat1052 {
    struct Node {
        int addr, value;

        Node(int addr, int value) : addr(addr), value(value) {}

        friend bool operator<(const Node &n1, const Node &n2) {
            return n1.value < n2.value;
        }
    };

    int key0[100010];
    int next0[100010];

    int main() {
        int n, headPos;
        cin >> n >> headPos;
        int addr, ky, nxt;
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &addr, &ky, &nxt);
            key0[addr] = ky;
            next0[addr] = nxt;
        }
        addr = headPos;
        vector<Node> ans;
        while (addr != -1) {
            ans.emplace_back(addr, key0[addr]);
            addr = next0[addr];
        }

        sort(ans.begin(), ans.end());

        cout << ans.size() << " ";
        if (ans.size() == 0) {
            cout << "-1" << endl;
        } else {
            printf("%05d\n", ans[0].addr);
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
