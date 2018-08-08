//
// Created by neild47 on 18-6-5.
//
#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;
namespace pat1026 {


#define OPEN_TIME (8*3600)
#define CLOSE_TIME (21*3600)

    struct player {
        int arrive;
        int startTime;
        int serveTime;
        int vip;
        int out;

        player() {
            arrive = serveTime = vip = out = startTime = 0;
        }

        friend bool operator<(const player &p1, const player &p2) {
            return p1.arrive < p2.arrive;
        }
    };

    int popTime[110];
    int countServe[110];
    set<int> vipTableNumbers;

    int main() {

        fill(popTime, popTime + 110, OPEN_TIME);

        int numPlayers;
        cin >> numPlayers;
        deque<player> players;
        for (int i = 0; i < numPlayers; i++) {
            int hh, mm, ss;
            scanf("%d:%d:%d", &hh, &mm, &ss);
            player p;
            p.arrive = hh * 3600 + mm * 60 + ss;
            cin >> p.serveTime;
            p.serveTime *= 60;
            if (p.serveTime > 7200) {
                p.serveTime = 7200;
            }
            cin >> p.vip;
            players.push_back(p);
        }

        sort(players.begin(), players.end());

        int numTables, numVipTables;
        cin >> numTables >> numVipTables;
        for (int i = 0; i < numVipTables; i++) {
            int v;
            cin >> v;
            vipTableNumbers.insert(v);
        }


        vector<player> ans;
        while (!players.empty()) {
            int table_idx;
            while (true) {// 如果拿到的是vip桌子，那么就查看是否有vip在队列中
                table_idx = static_cast<int>(min_element(popTime + 1, popTime + 1 + numTables) - popTime);
                if (vipTableNumbers.count(table_idx)) {
                    int ptime = popTime[table_idx];
                    if (ptime >= CLOSE_TIME) break;
                    auto iter = find_if(players.begin(), players.end(),
                                        [ptime](const player &p) { return p.vip && !p.out && p.arrive <= ptime; });
                    if (iter != players.end()) {
                        (*iter).out = 1;
                        (*iter).startTime = ptime;
                        ans.push_back(*iter);
                        countServe[table_idx]++;
                        popTime[table_idx] = ptime + (*iter).serveTime;
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }
            int ptime = popTime[table_idx];
            if (ptime >= CLOSE_TIME) break;
            while (players.front().out && !players.empty()) players.pop_front();
            if (players.empty()) break;
            auto p = players.front();
            players.pop_front();
            if (p.arrive >= CLOSE_TIME) break;
            if (p.vip) {// 如果队列首部的人是vip，那么就查看是否有空缺的vip桌子。
                int vip_table_idx = *min_element(vipTableNumbers.begin(), vipTableNumbers.end(),
                                                 [](int n1, int n2) {
                                                     if (popTime[n1] != popTime[n2])
                                                         return popTime[n1] < popTime[n2];
                                                     else return n1 < n2;
                                                 });
                if (popTime[vip_table_idx] <= p.arrive) {
                    popTime[vip_table_idx] = p.arrive + p.serveTime;
                    countServe[vip_table_idx]++;
                    p.startTime = p.arrive;
                    ans.push_back(p);
                    continue;
                }
            }
            if (p.arrive <= ptime) {
                p.startTime = ptime;
            } else {
                p.startTime = p.arrive;
            }

            popTime[table_idx] = p.startTime + p.serveTime;
            countServe[table_idx]++;
            ans.push_back(p);
        }

        sort(ans.begin(), ans.end(), [](const player &p1, const player &p2) {
            if (p1.startTime != p2.startTime) {
                return p1.startTime < p2.startTime;
            } else {
                return p1.arrive < p2.arrive;
            }
        });
        for (auto &p:ans) {
            printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", p.arrive / 3600, p.arrive % 3600 / 60, p.arrive % 60,
                   p.startTime / 3600, p.startTime % 3600 / 60, p.startTime % 60,
                   static_cast<int>(round((p.startTime - p.arrive) / 60.0)));
        }

        for (int i = 1; i <= numTables; i++) {
            if (i != 1) cout << " ";
            cout << countServe[i];
        }
        return 0;
    }
}
