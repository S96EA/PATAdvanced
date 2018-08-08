//
// Created by neild47 on 18-8-2.
//
#include <iostream>
#include <vector>

using namespace std;
namespace pat1120 {
    int cnt[110];

    int main() {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int v, fd = 0;
            scanf("%d", &v);
            while (v) {
                fd += v % 10;
                v /= 10;
            }
            cnt[fd]++;
        }

        vector<int> ans;
        for (int i = 1; i < 110; i++) {
            if (cnt[i]) ans.push_back(i);
        }
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++) {
            if (i != 0) cout << " ";
            cout << ans[i];
        }
        cout << endl;
        return 0;
    }
}
