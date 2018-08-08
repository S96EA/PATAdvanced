//
// Created by neild47 on 18-6-2.
//

#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <algorithm>
#include <list>

using namespace std;
namespace pat1016 {
    struct Entry {
        int dd, hh, mm, type;

        Entry(int dd, int hh, int mm, int type) : dd(dd), hh(hh), mm(mm), type(type) {}

        friend bool operator<(const Entry &e1, const Entry &e2) {
            if (e1.dd != e2.dd) return e1.dd < e2.dd;
            if (e1.hh != e2.hh) return e1.hh < e2.hh;
            if (e1.mm != e2.mm) return e1.mm < e2.mm;
            return false;
        }

        friend int operator-(const Entry &e1, const Entry &e2) {
            return (e1.dd - e2.dd) * 24 * 60 + (e1.hh - e2.hh) * 60 + (e1.mm - e2.mm);
        }

        void addOneMinute() {
            mm++;
            hh += mm / 60;
            dd += hh / 24;

            mm %= 60;
            hh %= 24;
        }
    };

    int tolls[24];

    int month;

    int getMoney(Entry e1, Entry e2) {
        int sum = 0;
        while (e1 < e2) {
            sum += tolls[e1.hh];
            e1.addOneMinute();
        }
        return sum;
    }

    int main() {
        map<string, deque<Entry>> entries;
        for (int i = 0; i < 24; i++) {
            cin >> tolls[i];
        }

        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string name, type;
            cin >> name;
            int dd, hh, mm;
            scanf("%d:%d:%d:%d", &month, &dd, &hh, &mm);
            cin >> type;
            if (type[1] == 'n') {//on-line
                entries[name].emplace_back(dd, hh, mm, 0);
            } else {//off-line
                entries[name].emplace_back(dd, hh, mm, 1);
            }
        }

        for (auto &item:entries) {
            sort(item.second.begin(), item.second.end());
        }

        map<string, vector<pair<Entry, Entry>>> ans;
        for (auto &item:entries) {
            auto &s1 = item.second;

            int i = 0;
            while (i + 1 < s1.size()) {
                if (s1[i].type == 0 && s1[i + 1].type == 1) {
                    ans[item.first].push_back(make_pair(s1[i], s1[i + 1]));
                    i += 2;
                } else {
                    i++;
                }
            }
        }

        for (auto &item:ans) {
            if (item.second.empty()) {
                continue;
            }

            cout << item.first << " ";
            printf("%02d\n", month);
            int sum = 0;
            for (auto ery:item.second) {
                printf("%02d:%02d:%02d %02d:%02d:%02d %d", ery.first.dd, ery.first.hh, ery.first.mm, ery.second.dd,
                       ery.second.hh, ery.second.mm, ery.second - ery.first);
                int s = getMoney(ery.first, ery.second);
                printf(" $%.2f\n", s / 100.0);
                sum += s;
            }
            printf("Total amount: $%.2f\n", sum / 100.0);
        }

        return 0;
    }
}
