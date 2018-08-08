//
// Created by neild47 on 18-7-11.
//
#include <iostream>
#include <vector>
#include <algorithm>

namespace pat1085 {
    using namespace std;

    int main() {
        int n;
        long p;
        cin >> n >> p;
        long v;
        vector<long> numbers;
        for (int i = 0; i < n; i++) {
            scanf("%ld", &v);
            numbers.push_back(v);
        }

        sort(numbers.begin(), numbers.end());

        int maxP = 0;
        for (auto item = numbers.begin(); item != numbers.end(); item++) {
            auto pos = upper_bound(numbers.begin(), numbers.end(), p * (*item)) - item;
            if (pos > maxP) {
                maxP = pos;
            }
        }
        cout << maxP << endl;
        return 0;
    }
}
