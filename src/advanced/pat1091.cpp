//
// Created by neild47 on 18-7-12.
//

#include <iostream>
#include <queue>
#include <array>

using namespace std;
namespace pat1091 {
    int L, M, N, T;

    bool slice[65][1300][140];
    bool vis[65][1300][140];

    int blockSize;

    void bfs(int i, int j, int k) {
        if (i < 0 || i >= L || j < 0 || j >= M || k < 0 || k >= N || vis[i][j][k]) return;

        if (slice[i][j][k]) {
            queue<array<int, 3>> bfsQueue;
            bfsQueue.push(array<int, 3>{i, j, k});

            while (!bfsQueue.empty()) {
                auto a = bfsQueue.front();
                bfsQueue.pop();
                i = a[0], j = a[1], k = a[2];
                if (i < 0 || i >= L || j < 0 || j >= M || k < 0 || k >= N || vis[i][j][k]) continue;
                vis[i][j][k] = true;

                if (slice[i][j][k]) {
                    blockSize++;
                    bfsQueue.push(array<int, 3>{i + 1, j, k});
                    bfsQueue.push(array<int, 3>{i - 1, j, k});
                    bfsQueue.push(array<int, 3>{i, j + 1, k});
                    bfsQueue.push(array<int, 3>{i, j - 1, k});
                    bfsQueue.push(array<int, 3>{i, j, k + 1});
                    bfsQueue.push(array<int, 3>{i, j, k - 1});
                }
            }
        }
    }

    int main() {
        cin >> M >> N >> L >> T;
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < M; j++) {
                for (int k = 0; k < N; k++) {
                    scanf("%d", &slice[i][j][k]);
                }
            }
        }

        int totalT = 0;
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < M; j++) {
                for (int k = 0; k < N; k++) {
                    if (!vis[i][j][k]) {
                        blockSize = 0;
                        bfs(i, j, k);
                        if (blockSize >= T) {
                            totalT += blockSize;
                        }
                    }
                }
            }
        }
        cout << totalT << endl;
        return 0;
    }
}
