//
// Created by neild47 on 18-7-20.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
namespace pat1101 {
    int N;
    int nums[100010];
    int maxE[100010];
    int minE[100010];

    int main() {
        cin >> N;
        for (int i = 0; i < N; i++) {
            scanf("%d", &nums[i]);
        }

        int maxEle = nums[0];
        maxE[0] = -1;
        for (int i = 1; i < N; i++) {
            maxE[i] = maxEle;

            if (nums[i] > maxEle) {
                maxEle = nums[i];
            }
        }

        int minEle = nums[N - 1];
        minE[N - 1] = INT32_MAX;
        for (int i = N - 2; i >= 0; i--) {
            minE[i] = minEle;
            if (nums[i] < minEle) {
                minEle = nums[i];
            }
        }

        vector<int> ans;
        for (int i = 0; i < N; i++) {
            if (nums[i] > maxE[i] && nums[i] < minE[i]) {
                ans.push_back(nums[i]);
            }
        }
        cout << ans.size() << endl;
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++) {
            if (i != 0) cout << " ";
            cout << ans[i];
        }
        cout << endl;
        return 0;
    }
}
