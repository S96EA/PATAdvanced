//
// Created by neild47 on 18-7-31.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
namespace pat1113 {
    int main() {
        int n;
        cin >> n;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int v;
            scanf("%d", &v);
            ans.push_back(v);
        }

        sort(ans.begin(), ans.end());
        printf("%d ", n % 2);
        int mid = n / 2;
        int s1 = 0, s2 = 0;
        for (int i = 0; i < mid; i++) {
            s1 += ans[i];
        }
        for (int i = mid; i < n; i++) {
            s2 += ans[i];
        }

        printf("%d", s2 - s1);
        return 0;
    }
}
