//
// Created by neild47 on 18-6-10.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

namespace pat1037 {
    int main() {
        int nc, np;
        vector<int> ncs, nps;
        cin >> nc;
        for (int i = 0; i < nc; ++i) {
            int value;
            scanf("%d", &value);
            ncs.push_back(value);
        }
        cin >> np;
        for (int i = 0; i < np; ++i) {
            int value;
            scanf("%d", &value);
            nps.push_back(value);
        }
        sort(ncs.begin(), ncs.end());
        sort(nps.begin(), nps.end());

        long long sum = 0;
        auto iterc = ncs.begin(), iterp = nps.begin();
        for (; *iterc < 0 && *iterp < 0; iterc++, iterp++) {
            sum += *iterc * *iterp;
        }

        auto riterc = ncs.rbegin(), riterp = nps.rbegin();
        for (; *riterc > 0 && *riterp > 0; riterc++, riterp++) {
            sum += *riterc * *riterp;
        }

        cout << sum << endl;
        return 0;
    }
}
