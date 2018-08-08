//
// Created by neild47 on 18-7-23.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
namespace pat1104 {
    int main() {
        int n;
        double v;
        cin >> n;
        vector<double> ans;
        for (int i = 0; i < n; i++) {
            scanf("%lf", &v);
            ans.push_back(v);
        }

        double s = 0;
        for (int i = 0; i < n; i++) {
            double prevn = i;
            double postn = n - i - 1;
            double t = prevn + postn + prevn * postn + 1;
            s += ans[i] * t;
        }
        printf("%.2lf", s);
        return 0;
    }
}
