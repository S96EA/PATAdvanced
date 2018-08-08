//
// Created by neild47 on 18-7-18.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
namespace pat1096 {


    vector<int> tmpPath;
    vector<int> longestPath;

    void dfs(int curr, int fa) {
        if (curr % fa == 0) {
            tmpPath.push_back(fa);
            dfs(curr / fa, fa + 1);
            if (longestPath.size() < tmpPath.size()) {
                longestPath = tmpPath;
            }
        }
    }

    bool isPrimer(int num) {
        for (int i = 2; i < sqrt(num); i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    int main() {
        int n;
        cin >> n;
        if (isPrimer(n)) {
            cout << 1 << endl;
            cout << n << endl;
            return 0;
        }

        for (int i = 2; i < sqrt(n); i++) {
            tmpPath.clear();
            dfs(n, i);
        }
        cout << longestPath.size() << endl;
        for (int i = 0; i < longestPath.size(); i++) {
            if (i != 0) cout << "*";
            cout << longestPath[i];
        }
        cout << endl;
        return 0;
    }
}
