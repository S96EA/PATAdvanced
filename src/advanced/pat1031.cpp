//
// Created by neild47 on 18-6-8.
//
#include <iostream>
#include <algorithm>

using namespace std;

namespace pat1031 {

    char us[50][50];

    int main() {
        fill(us[0], us[49] + 50, ' ');
        string s;
        cin >> s;
        int len = (int) s.size();
        int lenY = (len - 1) / 3;

        int iter = 0;
        for (int i = 0; i < lenY; i++) {
            us[i][0] = s[iter++];
        }
        int lenX = len - 2 * lenY;
//    cout << lenX << endl;
        for (int i = 0; i < lenX; i++) {
            us[lenY][i] = s[iter++];
        }

        for (int i = lenY - 1; i >= 0; i--) {
            us[i][lenX - 1] = s[iter++];
        }

        for (int i = 0; i <= lenY; i++) {
            for (int j = 0; j < lenX; j++) {
                cout << us[i][j];
            }
            cout << endl;
        }
        return 0;
    }
}
