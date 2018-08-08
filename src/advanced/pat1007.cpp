//
// Created by neild47 on 18-5-29.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace pat1007 {

    int main() {
        int k;
        cin >> k;
        int maxSum = INT32_MIN, iterSum = 0, firstNum = 0, lastNum = 0;

        vector<int> nums;

        for (int i = 0; i < k; i++) {
            int value;
            cin >> value;
            nums.push_back(value);
        }

        if (count_if(nums.begin(), nums.end(), [](int i) { return i >= 0; }) == 0) {
            cout << 0 << " " << nums[0] << " " << nums[k - 1] << endl;
            return 0;
        }

        int i = 0;
        int iterF = nums[0];
        while (i < k) {
            iterSum += nums[i];
            if (iterSum < 0) {
                i++;
                iterSum = 0;
                iterF = nums[i];
                continue;
            }
            if (iterSum > maxSum) {
                maxSum = iterSum;
                firstNum = iterF;
                lastNum = nums[i];
            }
            i++;
        }

        cout << maxSum << " " << firstNum << " " << lastNum << endl;
        return 0;
    }
}

