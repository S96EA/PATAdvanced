//
// Created by neild47 on 18-5-30.
//
#include <iostream>
#include <vector>

using namespace std;
namespace pat1011 {

    pair<double, int> findMax(double a, double b, double c) {
        if (a >= b && a >= c) return make_pair(a, 1);
        if (b >= a && b >= c) return make_pair(b, 2);
        else return make_pair(c, 3);
    }

    int main() {
        double sum = 1;
        vector<char> vs;
        for (int i = 0; i < 3; i++) {
            double a, b, c;
            cin >> a >> b >> c;
            pair<double, int> re = findMax(a, b, c);
            switch (re.second) {
                case 1:
                    vs.push_back('W');
                    break;
                case 2:
                    vs.push_back('T');
                    break;
                case 3:
                    vs.push_back('L');
                    break;
            }
            sum *= re.first;
        }

        for (auto c:vs) {
            cout << c << " ";
        }
        sum = (sum * 0.65 - 1) * 2;
        printf("%.2f\n", sum);
        return 0;
    }
}
