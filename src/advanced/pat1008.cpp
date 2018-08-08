//
// Created by neild47 on 18-5-29.
//
#include <iostream>
#include <vector>

using namespace std;
namespace pat1008 {
    int main() {
        int n;
        cin >> n;
        vector<int> requests;
        requests.push_back(0);
        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            requests.push_back(value);
        }

        vector<int> diff(requests.size() - 1);
        for (int i = 1; i <= n; i++) {
            diff[i - 1] = requests[i] - requests[i - 1];
        }

        int sumTime = 0;
        for (int i = 0; i < n; i++) {
            if (diff[i] > 0) {
                sumTime += diff[i] * 6;
            } else if (diff[i] < 0) {
                sumTime += -diff[i] * 4;
            }
        }
        sumTime += n * 5;
        cout << sumTime;
        return 0;
    }
}
