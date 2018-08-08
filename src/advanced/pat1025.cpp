//
// Created by neild47 on 18-6-5.
//
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

namespace pat1025 {
    using namespace std;

    struct Testee {
        long id;
        int score;
        int location;
        int location_rank;
        int rank;
    };

    bool comp(const Testee *t1, const Testee *t2) {
        return t1->score > t2->score;
    }

    bool compById(const Testee *t1, const Testee *t2) {
        return t1->id < t2->id;
    }

    deque<Testee *> testees[110];

    int main() {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int num_location;
            cin >> num_location;
            for (int j = 0; j < num_location; j++) {
                auto testee = new Testee;
                cin >> testee->id >> testee->score;
                testee->location = i;
                testees[i].push_back(testee);
            }

            //脑子抽了？ 直接写一个cmp函数处理分数相同的情况，sort一遍就可以了阿
            sort(testees[i].begin(), testees[i].end(), compById);
            stable_sort(testees[i].begin(), testees[i].end(), comp);

//        for (auto item0:testees[i]) {
//            printf("%013ld %d %d\n", item0->id, item0->location, item0->location_rank);
//        }

            auto item = 0;
            testees[i][item]->location_rank = 1;
            item++;
            while (item < testees[i].size()) {
                if (testees[i][item]->score == testees[i][item - 1]->score) {
                    testees[i][item]->location_rank = testees[i][item - 1]->location_rank;
                } else {
                    testees[i][item]->location_rank = item + 1;
                }
                item++;
            }

        }

        vector<Testee *> ans;

        while (true) {
            int minIdx = -1;
            int minScore = INT32_MIN;
            for (int i = 1; i <= n; i++) {
                if (testees[i].empty()) continue;
                if ((*testees[i].begin())->score > minScore
                    || (*testees[i].begin())->score == minScore &&
                       (*testees[i].begin())->id < (*testees[minIdx].begin())->id) {
                    minIdx = i;
                    minScore = (*testees[i].begin())->score;
                }
            }
            if (minIdx == -1) {
                break;
            }
            auto te = *testees[minIdx].begin();
            testees[minIdx].pop_front();

            ans.push_back(te);
        }

        cout << ans.size() << endl;

        int item = 0;
        ans[item]->rank = 1;
        while (++item < ans.size()) {
            if (ans[item]->score == ans[item - 1]->score) {
                ans[item]->rank = ans[item - 1]->rank;
            } else {
                ans[item]->rank = item + 1;
            }
        }

        for (auto item0:ans) {
            printf("%013ld %d %d %d\n", item0->id, item0->rank, item0->location, item0->location_rank);
        }

        return 0;
    }
}
