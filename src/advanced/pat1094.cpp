//
// Created by neild47 on 18-7-18.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
namespace pat1094 {
    int N, M;
    vector<int> family[110];

    int population[110];

    void dfs(int curr, int depth) {
        population[depth]++;
        for (auto c:family[curr]) {
            dfs(c, depth + 1);
        }
    }

    int main() {
        cin >> N >> M;
        for (int i = 0; i < M; i++) {
            int id, k, c;
            scanf("%d%d", &id, &k);
            for (int j = 0; j < k; j++) {
                scanf("%d", &c);
                family[id].push_back(c);
            }
        }

        dfs(1, 1);
        int pos = max_element(population, population + 110) - population;

        cout << population[pos] << " " << pos << endl;

        return 0;
    }
}
