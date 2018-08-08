//
// Created by neild47 on 18-6-29.
//
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

namespace pat1068 {
    int arr[100010];
    int posArr[100010];

    int main() {
        int n;
        cin >> n;
        set<int> unorderSets;
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            posArr[arr[i]] = i;
            if (arr[i] != i && arr[i] != 0) {
                unorderSets.insert(arr[i]);
            }
        }
        int pos0 = 0;
        while (arr[pos0] != 0) pos0++;

        int count = 0;
        while (true) {
            while (pos0 != 0) {
                arr[pos0] = pos0;
                int nextPos = posArr[pos0];
                posArr[pos0] = pos0;
                unorderSets.erase(pos0);
                pos0 = nextPos;
                posArr[0] = pos0;
                arr[pos0] = 0;
                count++;
            }

            if (unorderSets.empty()) break;

            int ret = *unorderSets.begin();
            unorderSets.erase(ret);

            int nextPos = posArr[arr[ret]];
            posArr[arr[ret]] = 0;
            posArr[0] = nextPos;
            arr[0] = arr[ret];
            arr[ret] = 0;
            pos0 = nextPos;
            count++;
        }
        cout << count << endl;
        return 0;
    }
}
