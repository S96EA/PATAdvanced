//
// Created by neild47 on 18-6-22.
//

#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

namespace pat1063 {

    int N;
    vector<set<int>> numbers(55);

    int main() {
        cin >> N;
        int n, v;
        for (int i = 1; i <= N; i++) {
            scanf("%d", &n);
            for (int j = 0; j < n; ++j) {
                scanf("%d", &v);
                numbers[i].insert(v);
            }
        }

//    for (int i = 0; i < N; i++) {
//        sort(numbers[i].begin(), numbers[i].end());
//    }

        vector<int> ans(10010);
        int nq, v1, v2;
        cin >> nq;
        for (int i = 0; i < nq; ++i) {
            scanf("%d%d", &v1, &v2);
            int nc = (int) (
                    set_intersection(numbers[v1].begin(), numbers[v1].end(), numbers[v2].begin(), numbers[v2].end(),
                                     ans.begin()) - ans.begin());
            int nt = (int) (numbers[v1].size() + numbers[v2].size() - nc);
            printf("%.1f%%\n", nc * 100.0 / nt);
        }
        return 0;
    }
}
