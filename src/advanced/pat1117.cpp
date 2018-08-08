//
// Created by neild47 on 18-8-1.
//
#include <iostream>

using namespace std;
namespace pat1117 {

    int arr[110000];

    int main() {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int v;
            scanf("%d", &v);
            if (v > n) {
                v = n + 1;
            }
            arr[v - 1]++;
        }

        for (int i = n - 1; i >= 0; i--) {
            arr[i] += arr[i + 1];
        }

//    for (int i = 0; i <= n; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
        int i = 0;
        while (i <= n && i <= arr[i]) {
            i++;
        }
        i--;

        cout << i << endl;
        return 0;
    }
}
