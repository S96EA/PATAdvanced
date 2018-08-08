//
// Created by neild47 on 18-6-8.
//
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;
namespace pat1034 {
    int id;

    unordered_map<string, int> nameToId;
    string idToName[2010];

    int getId(string &string1) {
        if (!nameToId.count(string1)) {
            nameToId[string1] = id;
            idToName[id] = string1;
            id++;
        }
        return nameToId[string1];
    }

    int N, K, numGangs;
    int calls[2010][2010], vis[2010];
    bool visCalls[2010][2010];
    int tmpSumCalls, tmpCounts, dfsCount = 1;

    void dfs(int u) {
        vis[u] = dfsCount;
        tmpCounts++;

        for (int i = 0; i < id; i++) {
            if (!vis[i] && calls[u][i]) {
                tmpSumCalls += calls[u][i];
                visCalls[u][i] = visCalls[i][u] = true;
                dfs(i);
            } else if (!visCalls[u][i]) {
                tmpSumCalls += calls[u][i];
                visCalls[i][u] = visCalls[u][i] = true;
            }
        }
    }

    int main() {
        cin >> N >> K;
        string s1, s2;
        int t;
        for (int i = 0; i < N; i++) {
            cin >> s1 >> s2 >> t;
            calls[getId(s1)][getId(s2)] += t;
            calls[getId(s2)][getId(s1)] += t;
        }

        vector<int> gangIds;
        for (int i = 0; i < id; i++) {
            if (!vis[i]) {
                tmpSumCalls = tmpCounts = 0;
                dfs(i);
                if (tmpSumCalls > K && tmpCounts > 2) {
                    gangIds.push_back(dfsCount);
                    numGangs++;
                }
                dfsCount++;
            }
        }

        cout << numGangs << endl;

        map<string, int> gangs;
        for (auto n:gangIds) {
            int maxCallId = -1;
            int maxCallTime = INT32_MIN;
            int members = 0;
            for (int i = 0; i < id; i++) {
                if (vis[i] == n) {
                    members++;
                    int tmpCallSum = 0;
                    for (int j = 0; j < id; j++) {
                        if (vis[j] == n) {
                            tmpCallSum += calls[j][i];
                        }
                    }
                    if (tmpCallSum > maxCallTime) {
                        maxCallTime = tmpCallSum;
                        maxCallId = i;
                    }
                }
            }
            if (maxCallId == -1) continue;
            gangs[idToName[maxCallId]] = members;
        }

        for (auto &p:gangs) {
            cout << p.first << " " << p.second << endl;
        }

        return 0;
    }
}
