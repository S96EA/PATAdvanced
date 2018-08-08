//
// Created by neild47 on 18-8-3.
//

#include <iostream>
#include <map>

using namespace std;
namespace pat1128 {
    int q[1010];

    int main() {
        int k;
        cin >> k;
        for (int i = 0; i < k; i++) {
            int n, v;
            map<int, int> diag1, diag2;
            scanf("%d", &n);
            fill(q, q + n + 1, 0);
            for (int j = 0; j < n; j++) {
                scanf("%d", &v);
                q[v]++;
                diag1[v - (j + 1)]++;
                diag2[v + j + 1]++;
            }

            bool ok = true;
            for (int j = 1; j <= n; j++) {
                if (q[j] != 1) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                for (auto &item:diag1) {
                    if (item.second != 1) {
                        ok = false;
                        break;
                    }
                }
                for (auto &item:diag2) {
                    if (item.second != 1) {
                        ok = false;
                        break;
                    }
                }
            }

            printf(ok ? "YES\n" : "NO\n");
        }
        return 0;
    }
}
