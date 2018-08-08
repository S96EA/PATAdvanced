//
// Created by neild47 on 18-8-6.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;
namespace pat1139 {


    vector<int> graph[10010];


    int main() {
        int n, m;
        cin >> n >> m;

        unordered_set<int> friends;
        for (int i = 0; i < m; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            int i1 = abs(atoi(s1.data()));
            int i2 = abs(atoi(s2.data()));
            if (s1.length() == s2.length()) {
                graph[abs(i1)].push_back(abs(i2));
                graph[abs(i2)].push_back(abs(i1));
            }
            friends.insert(i1 * 10000 + i2);
            friends.insert(i2 * 10000 + i1);
        }

        int q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            int i1, i2;
            cin >> i1 >> i2;
            i1 = abs(i1);
            i2 = abs(i2);
            vector<pair<int, int>> ans;
            for (auto k:graph[i1]) {
                if (k == i1 || k == i2) continue;
                for (auto l:graph[i2]) {
                    if (l == i1 || l == i2) continue;
                    if (friends.count(k * 10000 + l)) {
                        ans.emplace_back(k, l);
                    }
                }
            }
            sort(ans.begin(), ans.end());
            cout << ans.size() << endl;
            for (auto &p:ans) {
                printf("%04d %04d\n", p.first, p.second);
            }
        }

        return 0;
    }
}
