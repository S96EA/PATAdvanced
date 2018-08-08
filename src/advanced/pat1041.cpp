//
// Created by neild47 on 18-6-11.
//

#include <iostream>
#include <vector>

using namespace std;

namespace pat1041 {
    int cnt[10010];

    int main() {
        int n;
        cin >> n;
        vector<int> nums;
        nums.reserve(n + 10);
        int value;
        for (int i = 0; i < n; i++) {
            scanf("%d", &value);
            cnt[value]++;
            nums.push_back(value);
        }

        bool flag = false;
        for (auto i:nums) {
            if (cnt[i] == 1) {
                flag = true;
                cout << i << endl;
                break;
            }
        }

        if (!flag) {
            cout << "None" << endl;
        }
        return 0;
    }
}
