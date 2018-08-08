//
// Created by neild47 on 18-8-8.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
namespace pat1144 {


    int main() {
        int n, v;
        cin >> n;
        vector<int> ans;
        ans.reserve(n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &v);
            ans.push_back(v);
        }
        sort(ans.begin(), ans.end());
        auto end = unique(ans.begin(), ans.end());
        auto iter = lower_bound(ans.begin(), end, 1);
        int i = 1;
        bool ok = false;
        for (; iter != end; i++, iter++) {
            if (*iter != i) {
                cout << i << endl;
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << i << endl;
        }
        return 0;
    }
}
