//
// Created by neild47 on 18-6-19.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

namespace pat1056 {
    int ranks[100010];

    struct mouse {
        int id, weight, rank;
    };

    int main() {
        int np, ng;
        cin >> np >> ng;
        fill(ranks, ranks + np, -1);
        vector<int> weights;
        vector<int> orderToProgrammers;
        int v;
        for (int i = 0; i < np; i++) {
            cin >> v;
            weights.push_back(v);
        }

        for (int i = 0; i < np; i++) {
            cin >> v;
            orderToProgrammers.push_back(v);
        }

        vector<int> nextProgrammers;
        vector<int> tmpProgrammers;
        for (int i = 0; i < np; i++) {
            tmpProgrammers.push_back(orderToProgrammers[i]);
            if ((i + 1) % ng == 0 || (i + 1) == np) {
                auto me = max_element(tmpProgrammers.begin(), tmpProgrammers.end(),
                                      [&](int i1, int i2) { return weights[i1] < weights[i2]; });
                nextProgrammers.push_back(*me);
                for (auto item :tmpProgrammers) {
                    if (item != *me) {
                        ranks[item] = 0;
                    }
                }
                tmpProgrammers.clear();
            }
        }

        tmpProgrammers.clear();
        int iter = 1;
        while (!nextProgrammers.empty()) {
            if (nextProgrammers.size() == 1) {
                ranks[nextProgrammers[0]] = iter;
                break;
            }
            vector<int> newNextProgrammers;
            for (auto i = 0; i < nextProgrammers.size(); i++) {
                tmpProgrammers.push_back(nextProgrammers[i]);
                if ((i + 1) % ng == 0 || (i + 1) == nextProgrammers.size()) {
                    auto me = max_element(tmpProgrammers.begin(), tmpProgrammers.end(),
                                          [&](int i1, int i2) { return weights[i1] < weights[i2]; });
                    newNextProgrammers.push_back(*me);
                    for (auto item :tmpProgrammers) {
                        if (item != *me) {
                            ranks[item] = iter;
                        }
                    }
                    tmpProgrammers.clear();
                }
            }
            nextProgrammers = newNextProgrammers;
            iter++;
        }


        vector<mouse> ans;
        for (int i = 0; i < np; i++) {
            ans.push_back(mouse{i, ranks[i], -1});
        }

        sort(ans.begin(), ans.end(), [](const mouse &m1, const mouse &m2) { return m1.weight > m2.weight; });
        ans[0].rank = 1;
        for (int i = 1; i < ans.size(); i++) {
            if (ans[i].weight == ans[i - 1].weight) ans[i].rank = ans[i - 1].rank;
            else ans[i].rank = i + 1;
        }

        sort(ans.begin(), ans.end(), [](const mouse &m1, const mouse &m2) { return m1.id < m2.id; });
        for (int i = 0; i < ans.size(); i++) {
            if (i != 0) cout << " ";
            cout << ans[i].rank;
        }
        return 0;
    }
}
