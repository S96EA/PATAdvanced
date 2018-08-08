//
// Created by neild47 on 18-8-8.
//
#include <iostream>
#include <vector>

int N, M;

using namespace std;
namespace pat1146 {
    vector<int> graph[1010];

    vector<int> in(1010), tin(1010);

    int main() {
        int N, M;
        cin >> N >> M;


        for (int i = 0; i < M; i++) {
            int v1, v2;
            scanf("%d%d", &v1, &v2);
            graph[v1].push_back(v2);
            in[v2]++;
        }

        int K;
        cin >> K;
        int cnt = 0;
        for (int i = 0; i < K; i++) {
            bool error = false;
            tin = in;
            for (int j = 0; j < N; j++) {
                int v;
                scanf("%d", &v);
                if (tin[v] != 0) {
                    error = true;
                }

                for (auto g:graph[v]) {
                    tin[g]--;
                }
            }
            if (error) {
                if (cnt) printf(" ");
                printf("%d", i);
                cnt++;
            }
        }
        return 0;
    }
}
