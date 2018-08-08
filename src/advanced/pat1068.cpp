//
// Created by neild47 on 18-6-28.
//

// 0-1背包问题，可以使用dp来做
// 这里并没有使用0-1背包来做，简单的使用回溯剪枝做的。
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
namespace pat1069 {

    int N, M;
    int coins[10010];
    int coinsSum[10010];

    vector<int> tmpPath;
    vector<vector<int>> paths;
    bool isOk = false;

    void dfs(int curr, int sum0) {
        if (isOk || curr > N || sum0 > M) return;
        if (sum0 + coinsSum[N - 1] - coinsSum[curr - 1] < M) return;
        if (sum0 == M) {
            paths.push_back(tmpPath);
            isOk = true;
            return;
        }
        tmpPath.push_back(coins[curr]);
        dfs(curr + 1, sum0 + coins[curr]);
        tmpPath.pop_back();

        dfs(curr + 1, sum0);
    }

    int main() {
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            scanf("%d", &coins[i]);
        }
        sort(coins, coins + N);
        coinsSum[0] = coins[0];
        for (int i = 1; i < N; i++) {
            coinsSum[i] = coinsSum[i - 1] + coins[i];
        }
        dfs(0, 0);

        if (paths.empty()) {
            cout << "No Solution" << endl;
        } else {
            vector<int> &vs = paths[0];
            for (int i = 0; i < vs.size(); i++) {
                if (i != 0) printf(" ");
                printf("%d", vs[i]);
            }
            cout << endl;
        }
        return 0;
    }
}
