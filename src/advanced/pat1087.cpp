//
// Created by neild47 on 18-7-11.
//
#include <iostream>
#include <algorithm>
#include <vector>

namespace pat1087 {

    using namespace std;
#define INF 999999999

    int N_Cities, N_Routes;

    int s1 = 26 * 26;
    int s2 = 26;

    int happiness[18000];
    vector<pair<int, int>> roads[18000];
    bool vis[18000];
    int dis[18000];

    vector<int> paths[18000];

    int nameToID(string name) {
        int ids = 0;
        for (int i = 0; i < 3; i++) {
            ids = ids * 26 + (name[i] - 'A');
        }
        return ids;
    }

    string idToName(int id) {
        string name;
        for (int i = 0; i < 3; i++) {
            name.push_back((id % 26) + 'A');
            id /= 26;
        }
        reverse(name.begin(), name.end());
        return name;
    }

    int numMinDisRoads = 0;

    int startId, destId;
    vector<int> bestHappPaths;
    int bestSumHapp = -1;
    vector<int> tmpPath;
    int tmpSumHapp;

    void dfs(int curr) {
        if (curr == startId) {
            numMinDisRoads++;
            if (tmpSumHapp > bestSumHapp) {
                bestHappPaths = tmpPath;
                bestSumHapp = tmpSumHapp;
            } else if (tmpSumHapp == bestSumHapp && tmpPath.size() < bestHappPaths.size()) {
                bestHappPaths = tmpPath;
            }
            return;
        }
        for (auto item:paths[curr]) {
            tmpSumHapp += happiness[item];
            tmpPath.push_back(curr);
            dfs(item);
            tmpPath.pop_back();
            tmpSumHapp -= happiness[item];
        }
    }

    int main() {
        fill(dis, dis + 18000, INF);

        string startC;
        cin >> N_Cities >> N_Routes >> startC;
        startId = nameToID(startC), destId = nameToID("ROM");
        string name, n2;
        int v;
        for (int i = 0; i < N_Cities - 1; i++) {
            cin >> name >> v;
            happiness[nameToID(name)] = v;
        }

        for (int i = 0; i < N_Routes; i++) {
            cin >> name >> n2 >> v;
            int i1 = nameToID(name), i2 = nameToID(n2);
            roads[i1].emplace_back(i2, v);
            roads[i2].emplace_back(i1, v);
        }

        dis[startId] = 0;

        for (int i = 0; i < 18000; i++) {
            int minId = -1, minDis = INF;
            for (int j = 0; j < 18000; j++) {
                if (!vis[j] && dis[j] < minDis) {
                    minDis = dis[j];
                    minId = j;
                }
            }

            if (minId == -1) break;
            vis[minId] = true;

            for (auto &item:roads[minId]) {
                int j = item.first;
                if (!vis[j] && item.second != INF) {
                    if (dis[minId] + item.second < dis[j]) {
                        dis[j] = dis[minId] + item.second;
                        paths[j].clear();
                        paths[j].push_back(minId);
                    } else if (dis[minId] + item.second == dis[j]) {
                        paths[j].push_back(minId);
                    }
                }
            }
        }

        tmpSumHapp = happiness[destId];
        dfs(destId);
        cout << numMinDisRoads << " " << dis[destId] << " " << bestSumHapp << " " << bestSumHapp / bestHappPaths.size()
             << endl;
        bestHappPaths.push_back(startId);
        reverse(bestHappPaths.begin(), bestHappPaths.end());
        for (int i = 0; i < bestHappPaths.size(); i++) {
            if (i != 0) printf("->");
            cout << idToName(bestHappPaths[i]);
        }
        return 0;
    }
}
