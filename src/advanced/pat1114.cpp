//
// Created by neild47 on 18-7-31.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
namespace pat1114 {
    struct people {
        int m;
        double area;
    };

    struct family {
        int id, numPeoples;
        double numEstates, areas;
    };

    people estateInfo[11000];
    vector<int> graph[11000];
    bool vis[11000];

    family f;

    void dfs(int curr) {
        if (curr == -1 || vis[curr]) return;

        vis[curr] = true;
        f.numPeoples++;
        f.id = min(f.id, curr);
        f.numEstates += estateInfo[curr].m;
        f.areas += estateInfo[curr].area;

        for (auto item:graph[curr]) {
            dfs(item);
        }
    }

    int main() {
        int n;
        cin >> n;
        vector<int> ids;
        for (int i = 0; i < n; i++) {
            int id, fa, mo, k, ch;
            scanf("%d%d%d%d", &id, &fa, &mo, &k);
            ids.push_back(id);

            if (fa != -1) {
                graph[id].push_back(fa);
                graph[fa].push_back(id);
            }
            if (mo != -1) {
                graph[id].push_back(mo);
                graph[mo].push_back(id);
            }

            for (int j = 0; j < k; j++) {
                scanf("%d", &ch);
                graph[id].push_back(ch);
                graph[ch].push_back(id);
            }

            scanf("%d%d", &fa, &mo);
            estateInfo[id].m = fa;
            estateInfo[id].area = mo;
        }

        vector<family> ans;
        for (auto i:ids) {
            if (!vis[i]) {
                f = family{99999999, 0, 0, 0};
                dfs(i);
                f.areas /= f.numPeoples;
                f.numEstates /= f.numPeoples;
                ans.push_back(f);
            }
        }

        cout << ans.size() << endl;
        sort(ans.begin(), ans.end(), [](const family &f1, const family &f2) {
            if (f1.areas != f2.areas) return f1.areas > f2.areas;
            return f1.id < f2.id;
        });
        for (auto fam:ans) {
            printf("%04d %d %.3f %.3f\n", fam.id, fam.numPeoples, fam.numEstates, fam.areas);
        }
        return 0;
    }
}
