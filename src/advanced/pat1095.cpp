//
// Created by neild47 on 18-7-18.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

namespace pat1095 {

    using namespace std;

    struct Car {
        char plate[10];
        int inTime, outTime;
    };

    int N, K;

    int main() {
        cin >> N >> K;
        vector<Car *> rowV;
        char cmd[5];
        for (int i = 0; i < N; i++) {
            int hh, mm, ss;
            Car *c = new Car{};
            scanf("%s %d:%d:%d %s", c->plate, &hh, &mm, &ss, cmd);
            if (cmd[0] == 'i') {//in
                c->inTime = hh * 3600 + mm * 60 + ss;
                c->outTime = -1;
            } else {//out
                c->outTime = hh * 3600 + mm * 60 + ss;
                c->inTime = -1;
            }
            rowV.push_back(c);
        }
        sort(rowV.begin(), rowV.end(), [](const Car *c1, const Car *c2) {
            int sc = strcmp(c1->plate, c2->plate);
            if (sc) {
                return sc < 0;
            }
            return max(c1->inTime, c1->outTime) < max(c2->inTime, c2->outTime);
        });

        vector<Car *> ans;
        for (int i = 0; i + 1 < rowV.size(); i++) {
            if (!strcmp(rowV[i]->plate, rowV[i + 1]->plate) && rowV[i]->inTime != -1 && rowV[i + 1]->outTime != -1 &&
                rowV[i]->inTime != rowV[i]->outTime) {
                rowV[i]->outTime = rowV[i + 1]->outTime;
                ans.push_back(rowV[i]);
            }
        }

        sort(ans.begin(), ans.end(), [](const Car *c1, const Car *c2) { return c1->inTime < c2->inTime; });
        vector<Car *> ans2 = ans;
        sort(ans2.begin(), ans2.end(), [](const Car *c1, const Car *c2) { return c1->outTime < c2->outTime; });

        int lastS = 0, inNum = 0, outNum = 0, lastO = 0;
        for (int i = 0; i < K; i++) {
            int hh, mm, ss;
            scanf("%d:%d:%d", &hh, &mm, &ss);
            int t = hh * 3600 + mm * 60 + ss;
            int j;
            for (j = lastS; j < ans.size(); j++) {
                if (ans[j]->inTime > t) {
                    break;
                }
                inNum++;
            }
            lastS = j;

            for (j = lastO; j < ans2.size(); j++) {
                if (ans2[j]->outTime > t) {
                    break;
                }
                outNum++;
            }
            lastO = j;
            printf("%d\n", inNum - outNum);
        }

        map<string, int> maps;
        for (auto c:ans) {
            maps[c->plate] += c->outTime - c->inTime;
        }
        vector<string> longest;
        int lt = -1;
        for (auto c:maps) {
            if (c.second > lt) {
                lt = c.second;
                longest.clear();
                longest.push_back(c.first);
            } else if (c.second == lt) {
                longest.push_back(c.first);
            }
        }

        sort(longest.begin(), longest.end(), [](const string &s1, const string &s2) { return s1 < s2; });
        for (int i = 0; i < longest.size(); i++) {
            cout << longest[i] << " ";
        }
        printf("%02d:%02d:%02d\n", lt / 3600, lt % 3600 / 60, lt % 60);

        return 0;
    }
}
