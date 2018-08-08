//
// Created by neild47 on 18-8-2.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
namespace pat1125 {
    int main() {
        int n;
        cin >> n;

        vector<double> segments;
        segments.reserve(n);
        double v;
        for (int i = 0; i < n; i++) {
            scanf("%lf", &v);
            segments.push_back(v);
        }

        sort(segments.begin(), segments.end());

        double length = segments[0];

        for (int i = 0; i < segments.size(); i++) {
            length = length / 2 + segments[i] / 2;
        }
        cout << (int) length << endl;

        return 0;
    }
}
