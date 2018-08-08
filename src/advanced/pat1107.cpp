//
// Created by neild47 on 18-7-23.
//

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

namespace pat1107 {

    using namespace std;

    int findH(int);

    void unionH(int, int);

    int hobbies[1010];

    int sizeH(int h) {
        int s = hobbies[findH(h)];
        return -s;
    }

    void unionH(int h1, int h2) {
        if (findH(h1) == findH(h2)) return;

        int s1 = sizeH(h1);

        hobbies[findH(h1)] = findH(h2);
        hobbies[findH(h2)] -= s1;
    }

    int findH(int h) {
        if (hobbies[h] < 0) {
            return h;
        }
        return hobbies[h] = findH(hobbies[h]);
    }

    int h[1010];

    int main() {
        int n;
        cin >> n;

        for (int i = 0; i < 1010; i++) {
            hobbies[i] = -1;
        }


        for (int i = 0; i < n; i++) {
            int k, f, v;
            scanf("%d:", &k);
            scanf("%d", &f);
            h[i] = f;
            for (int j = 1; j < k; j++) {
                scanf("%d", &v);
                unionH(f, v);
            }
        }

        int ans[1010] = {0};

        for (int i = 0; i < n; i++) {
            ans[findH(h[i])]++;
//        cout << findH(h[i]) << " " << ans[findH(h[i])] << endl;
        }
        vector<int> oans;
        for (int i = 1; i <= 1000; i++) {
            if (ans[i] != 0) {
                oans.push_back(ans[i]);
            }
        }
        sort(oans.begin(), oans.end(), std::greater<int>());
        cout << oans.size() << endl;
        for (int i = 0; i < oans.size(); i++) {
            if (i != 0) cout << " ";
            cout << oans[i];
        }

        return 0;
    }
}
