//
// Created by neild47 on 18-8-7.
//

#include <iostream>
#include <vector>

namespace pat1140 {
    using namespace std;

    int main() {
        int d, n;
        cin >> d >> n;
        vector<int> ans, tmp, bbb;
        ans.push_back(d);
        for (int i = 1; i < n; i++) {
            tmp.clear();
            for (int k = 0; k < ans.size();) {
                int t = ans[k];
                int cnt = 0;
                while (k < ans.size() && ans[k] == t) {
                    cnt++, k++;
                }
                tmp.push_back(t);
                if (cnt > 10) {
                    tmp.push_back(cnt / 10);
                    tmp.push_back(cnt % 10);
                } else {
                    tmp.push_back(cnt);
                }
            }
            ans = tmp;
        }

        for (auto item:ans) {
            cout << item;
        }
        return 0;
    }
}
