//
// Created by neild47 on 18-6-1.
//
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
namespace pat1014 {


    struct Custom {
        int id;
        int time;

        Custom(int id, int time) : id(id), time(time) {}
    };

    queue<Custom> windows[20];
    int sumTime[20];
    int popTime[20];

    int customTime[1001];
    int caterTime[1001];

    int maxTime = 60 * 9;

    int main() {
        int n, m, k, q;
        cin >> n >> m >> k >> q;
        fill(popTime, popTime + 20, INT32_MAX);

        int i = 0;
        for (; i < m * n && k > 0; i++, k--) {
            int value;
            cin >> value;
            windows[i % n].emplace(i + 1, value);
            sumTime[i % n] += value;
        }
        for (int j = 0; j < n; j++) {
            popTime[j] = windows[j].front().time;
            caterTime[windows[j].front().id] = 0;
        }


        while (k > 0) {
            int w_in = min_element(popTime, popTime + n) - popTime;

            int value;
            cin >> value;

            customTime[windows[w_in].front().id] = popTime[w_in];
            caterTime[windows[w_in].front().id] = popTime[w_in] - windows[w_in].front().time;
            windows[w_in].pop();
            windows[w_in].emplace(i + 1, value);
            popTime[w_in] += windows[w_in].front().time;

            i++;
            k--;
        }

        for (int i = 0; i < n; i++) {
            while (!windows[i].empty()) {
                auto c = windows[i].front();
                customTime[c.id] = popTime[i];
                caterTime[c.id] = popTime[i] - c.time;
                windows[i].pop();
                if (windows[i].empty())
                    break;
                popTime[i] += windows[i].front().time;
            }
        }


        for (int i = 0; i < q; i++) {
            int id;
            cin >> id;
            if (caterTime[id] == -1 || caterTime[id] >= maxTime) {
                cout << "Sorry" << endl;
                continue;
            }

            int t = customTime[id];
            int h = t / 60 + 8;
            int m = t % 60;
            printf("%02d:%02d\n", h, m);
        }

        return 0;
    }
}

