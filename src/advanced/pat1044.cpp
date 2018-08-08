//
// Created by neild47 on 18-6-12.
//
#include <iostream>
#include <vector>

using namespace std;

namespace pat1044 {

    int main() {
        int N, M;
        cin >> N >> M;
        vector<int> arr(N + 10);
        for (int i = 1; i <= N; i++) {
            scanf("%d", &arr[i]);
        }

        int i = 1, j;
        int tmpSum = 0;
        int ansSum = INT32_MAX;
        vector<pair<int, int>> ansPair;
        while (i <= N) {
            j = i;
            tmpSum = 0;
            while (tmpSum < M && j <= N) {
                tmpSum += arr[j];
                j++;
            }
            if (j == N + 1 && tmpSum < M) break;
            if (tmpSum < ansSum) {
                ansSum = tmpSum;
                ansPair.clear();
                ansPair.emplace_back(i, j - 1);
            } else if (tmpSum == ansSum) {
                ansPair.emplace_back(i, j - 1);
            }
            i++;
        }
        for (auto &item:ansPair) {
            printf("%d-%d\n", item.first, item.second);
        }
        return 0;
    }
}
