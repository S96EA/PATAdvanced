//
// Created by neild47 on 18-6-13.
//

#include <iostream>
#include <vector>

using namespace std;

namespace pat1046 {
    int main() {
        int n;
        cin >> n;
        vector<int> rowData(n + 1);
        rowData[0] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &rowData[i]);
        }

        vector<int> sum0(n + 1);
        for (int i = 0; i < n; i++) {
            sum0[i + 1] = sum0[i] + rowData[i + 1];
        }
        int q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            printf("%d\n", min(sum0[n] - (abs(sum0[a - 1] - sum0[b - 1])), abs(sum0[a - 1] - sum0[b - 1])));
        }
        return 0;
    }
}
