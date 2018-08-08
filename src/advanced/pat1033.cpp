//
// Created by neild47 on 18-6-8.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace pat1033 {
    struct station {
        double price;
        int dis;

        station() {}

        station(double price, int dis) : price(price), dis(dis) {}
    };

    int CMax, Dis, Avg, NumStations;
    double currGas, currMoney;
    station *currStation = nullptr;
    double MaxDis;

    auto cmpByDis = [](const station &s1, const station &s2) { return s1.dis < s2.dis; };
    auto cmpByPrice = [](const station *s1, const station *s2) { return s1->price < s2->price; };

    int main() {
        cin >> CMax >> Dis >> Avg >> NumStations;
        MaxDis = CMax * Avg;
        vector<station> stations;
        for (int i = 0; i < NumStations; i++) {
            station sta;
            cin >> sta.price >> sta.dis;
            stations.push_back(sta);
        }

        sort(stations.begin(), stations.end(), cmpByDis);
        stations.emplace_back(0.0, Dis);

        if (stations[0].dis != 0) {
            cout << "The maximum travel distance = 0.00" << endl;
            return 0;
        }

        currStation = &stations[0];
        for (;;) {
            if (currStation->dis == Dis) {
                printf("%.2f\n", currMoney);
                break;
            }

            vector<station *> couldMoveTo;
            for (auto &station : stations) {
                if (station.dis <= currStation->dis + MaxDis && station.dis > currStation->dis)
                    couldMoveTo.push_back(&station);
            }
            if (couldMoveTo.empty()) {
                printf("The maximum travel distance = %.2f\n", currStation->dis + MaxDis);
                break;
            }

            auto lowerPriceStation = find_if(couldMoveTo.begin(), couldMoveTo.end(),
                                             [currStation](const station *s) { return s->price < currStation->price; });
            if (lowerPriceStation != couldMoveTo.end()) {
                auto needGas = ((*lowerPriceStation)->dis - currStation->dis) * 1.0 / Avg;
                if (currGas < needGas) {
                    currMoney += (needGas - currGas) * currStation->price;
                    currGas = needGas;
                }
                currGas -= needGas;
                currStation = (*lowerPriceStation);
                continue;
            }
            currMoney += (CMax - currGas) * currStation->price;
            currGas = CMax;
            auto minPriceStation = min_element(couldMoveTo.begin(), couldMoveTo.end(), cmpByPrice);

            currGas -= ((*minPriceStation)->dis - currStation->dis) * 1.0 / Avg;
            currStation = (*minPriceStation);
        }
        return 0;
    }
}
