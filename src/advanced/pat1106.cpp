//
// Created by neild47 on 18-7-23.
//

#include <iostream>
#include <vector>
#include <cmath>

namespace pat1106 {
    using namespace std;
    int N;
    double P, R;

    vector<int> retailers[100010];

    int minDeepth = 999999999, nPaths = 0;

    void dfs(int curr, int depth) {
        if (retailers[curr].empty()) {
            if (depth < minDeepth) {
                nPaths = 1;
                minDeepth = depth;
            } else if (depth == minDeepth) {
                nPaths++;
            }
        } else {
            for (auto v:retailers[curr]) {
                dfs(v, depth + 1);
            }
        }
    }

    int main() {
        cin >> N >> P >> R;
        R /= 100;
        for (int i = 0; i < N; i++) {
            int k, v;
            scanf("%d", &k);
            for (int j = 0; j < k; j++) {
                scanf("%d", &v);
                retailers[i].push_back(v);
            }
        }

        dfs(0, 0);

        double fei = pow((1 + R), minDeepth) * P;
        printf("%.4f %d", fei, nPaths);
        return 0;
    }
}
