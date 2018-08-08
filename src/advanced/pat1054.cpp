//
// Created by neild47 on 18-6-19.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace pat1054 {
    int main() {
        int m, n;
        cin >> m >> n;
        int s = m * n, v;
        int k = 1;
        int sv;
        scanf("%d", &sv);
        for (int i = 1; i < s; i++) {
            scanf("%d", &v);
            if (v == sv) k++;
            else if (k > 0) k--;
            else if (k == 0) {
                sv = v;
                k = 1;
            }
        }
        cout << sv << endl;
        return 0;
    }
}
