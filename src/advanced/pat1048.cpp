//
// Created by neild47 on 18-6-13.
//
#include <iostream>

using namespace std;
namespace pat1048 {
    int moneys[1010];

    int main() {
        int n, m, v;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &v);
            moneys[v]++;
        }

        bool ok = false;
        for (int i = 1; i <= 500; i++) {
            if (moneys[i]-- && moneys[m - i]) {
                cout << i << " " << m - i << endl;
                ok = true;
                break;
            } else {
                moneys[i]++;
            }
        }
        if (!ok) {
            cout << "No Solution" << endl;
        }
        return 0;
    }
}
