//
// Created by neild47 on 18-8-2.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

namespace pat1121 {
    int cp[100010];
    bool vis[100010];

    int main() {
        fill(cp, cp + 100010, -1);
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int v1, v2;
            scanf("%d%d", &v1, &v2);
            cp[v1] = v2;
            cp[v2] = v1;
        }

        vector<int> guests;
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            int v;
            scanf("%d", &v);
            guests.push_back(v);
            vis[v] = true;
        }

        sort(guests.begin(), guests.end());

        vector<int> ans;

        for (auto guest:guests) {
            if (cp[guest] == -1 || !vis[cp[guest]]) {
                ans.push_back(guest);
            }
        }

        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++) {
            if (i) printf(" ");
            printf("%05d", ans[i]);
        }
        return 0;
    }
}
