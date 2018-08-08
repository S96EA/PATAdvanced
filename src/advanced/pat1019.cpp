//
// Created by neild47 on 18-6-4.
//
#include <iostream>
#include <vector>

using namespace std;

namespace pat1019 {

    vector<int> num;

    void spread(int n, int base) {
        while (n != 0) {
            num.push_back(n % base);
            n /= base;
        }
    }

    bool isP() {
        int i = 0, j = num.size() - 1;
        while (i < j) {
            if (num[i] != num[j]) return false;

            i++;
            j--;
        }
        return true;
    }

    int main() {
        int n, base;
        cin >> n >> base;
        spread(n, base);

        if (isP()) {
            cout << "Yes" << endl;

        } else {
            cout << "No" << endl;
        }
        if (num.size() == 0) {
            cout << "0";
        } else {
            for (int i = num.size() - 1; i >= 0; i--) {
                if (i != num.size() - 1) {
                    cout << " ";
                }
                cout << num[i];
            }
        }
        cout << endl;

        return 0;
    }
}
