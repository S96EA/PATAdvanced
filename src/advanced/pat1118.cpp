//
// Created by neild47 on 18-8-1.
//
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
namespace pat1118 {


    const int NB = 10010;

    int unionFindSet[NB];
    bool vis[NB];

    int find0(int i) {
        if (unionFindSet[i] == i) return i;
        return unionFindSet[i] = find0(unionFindSet[i]);
    }

    void union0(int i1, int i2) {
        int s1 = find0(i1);
        int s2 = find0(i2);

        if (s1 != s2) {
            unionFindSet[s1] = s2;
        }

    }

    int main() {
        for (int i = 0; i < NB; i++) unionFindSet[i] = i;

        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int k, v, u;
            scanf("%d", &k);
            if (!k) continue;
            scanf("%d", &v);
            vis[v] = true;
            for (int j = 1; j < k; j++) {
                scanf("%d", &u);
                vis[u] = true;
                union0(v, u);
            }
        }

        set<int> trees;
        int numBirds = 0;
        for (int i = 1; i < NB; i++) {
            if (vis[i]) {
                trees.insert(find0(i));
                numBirds++;
            }
        }
        cout << trees.size() << " " << numBirds << endl;

        int k;
        cin >> k;
        for (int i = 0; i < k; i++) {
            int v1, v2;
            scanf("%d%d", &v1, &v2);

            if (find0(v1) == find0(v2)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
        return 0;
    }
}
