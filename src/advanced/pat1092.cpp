//
// Created by neild47 on 18-7-18.
//

#include <iostream>

using namespace std;
namespace pat1092 {


    int cnt[300];

    int main() {
        string a1, a2;
        cin >> a1 >> a2;
        for (auto c:a1) {
            cnt[c]++;
        }

        int loss = 0;
        for (auto c:a2) {
            if (cnt[c] == 0) loss++;
            else cnt[c]--;
        }

        if (loss) {
            cout << "No " << loss;
        } else {
            int ext = 0;
            for (int i = 0; i < 300; i++) {
                ext += cnt[i];
            }
            cout << "Yes " << ext;
        }
        return 0;
    }
}
