//
// Created by neild47 on 18-6-2.
//

#include <iostream>
#include <vector>

using namespace std;
namespace pat1018 {

#define INF 99999999

    int cmax, numStations, dst, numRoads;

    int roads[510][510];
    int bikes[510];
    int visit[510];
    int dis[510];

    vector<int> paths[510];

    vector<int> tmpPath;

    int minNeed = INF, minTake = INF;

    vector<int> minPath;

    void dfs(int v) {
        if (v == 0) {
            tmpPath.push_back(v);
            int tmpNeed = 0, tmpTake = 0;
            for (auto sta = tmpPath.rbegin(); sta != tmpPath.rend(); sta++) {
                if (bikes[*sta] >= 0) {//take
                    tmpTake += bikes[*sta];
                } else {//need
                    int ned = -bikes[*sta];
                    if (ned <= tmpTake) tmpTake -= ned;
                    else {
                        tmpNeed += ned - tmpTake;
                        tmpTake = 0;
                    }
                }
            }
            if (tmpNeed < minNeed) {
                minNeed = tmpNeed;
                minTake = tmpTake;
                minPath = tmpPath;
            } else if (tmpNeed == minNeed && tmpTake < minTake) {
                minTake = tmpTake;
                minPath = tmpPath;
            }
            tmpPath.pop_back();
            return;
        }

        tmpPath.push_back(v);
        for (auto nei:paths[tmpPath.back()]) {
            dfs(nei);
        }
        tmpPath.pop_back();
    }

    int main() {
        fill(dis, dis + 510, INF);
        fill(roads[0], roads[0] + 510 * 510, INF);

        cin >> cmax >> numStations >> dst >> numRoads;

        for (int i = 1; i <= numStations; i++) {
            cin >> bikes[i];
            bikes[i] = bikes[i] - cmax / 2;//>0:take <0:need
        }

        for (int i = 0; i < numRoads; i++) {
            int s1, s2, t;
            cin >> s1 >> s2 >> t;
            roads[s1][s2] = roads[s2][s1] = t;
        }


        dis[0] = 0;

        for (int i = 0; i <= numStations; i++) {
            int minDis = INF;
            int minStation = -1;
            for (int j = 0; j <= numStations; j++) {
                if (dis[j] < minDis && visit[j] == 0) {
                    minDis = dis[j];
                    minStation = j;
                }
            }

            if (minStation == -1) {
                break;
            }

            visit[minStation] = 1;

            for (int j = 0; j <= numStations; j++) {
                if (visit[j] == 0 && roads[minStation][j] != INF) {
                    if (roads[minStation][j] + dis[minStation] < dis[j]) {
                        dis[j] = roads[minStation][j] + dis[minStation];
                        paths[j].clear();
                        paths[j].push_back(minStation);
                    } else if (roads[minStation][j] + dis[minStation] == dis[j]) {
                        paths[j].push_back(minStation);
                    }
                }
            }
        }


        dfs(dst);

        cout << minNeed << " ";
        for (auto i = minPath.rbegin(); i != minPath.rend(); i++) {
            if (i != minPath.rbegin()) {
                cout << "->";
            }
            cout << *i;
        }
        cout << " " << minTake << endl;

        return 0;
    }
}
