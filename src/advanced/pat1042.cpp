//
// Created by neild47 on 18-6-12.
//

#include <iostream>
#include <algorithm>

using namespace std;

namespace pat1042 {
    const string ms = "SHCDJ";

    int main() {
        int times;
        int row[55], shuffleArr[55];
        for (int i = 0; i < 55; i++) {
            row[i] = i;
        }

        cin >> times;
        int value;
        for (int i = 1; i < 55; i++) {
            cin >> value;
            shuffleArr[i] = value;
        }
        int tmp[55];
        for (int t = 0; t < times; t++) {
            for (int i = 1; i < 55; i++) {
                tmp[shuffleArr[i]] = row[i];
            }
            copy(tmp, tmp + 55, row);
        }

        for (int i = 1; i < 55; i++) {
            int v = row[i];
            if (i != 1) cout << " ";
            cout << ms[(v - 1) / 13] << v - ((v - 1) / 13) * 13;
        }
        return 0;
    }
}
