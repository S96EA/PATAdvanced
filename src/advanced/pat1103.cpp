//
// Created by neild47 on 18-7-20.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
namespace pat1103 {
    int N, K, P;

    bool cmp(const vector<int> &v1, const vector<int> &v2) {
        int s1 = 0;
        for (auto i:v1) {
            s1 += i;
        }
        int s2 = 0;
        for (auto i:v2) {
            s2 += i;
        }
        if (s1 != s2) return s1 > s2;

        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] != v2[i]) {
                return v1[i] > v2[i];
            }
        }
        return false;
    }

    bool visited[410][410];
    vector<int> paths[410][410];
    vector<int> tmpPath;
    vector<int> bestPath;

    void dfs(int currN, int currK) {
        if (currN < 0 || currK < 0) return;

        if (visited[currN][currK]) {
            if (!paths[currN][currK].empty()) {
                auto tt = tmpPath;
                for (auto i:paths[currN][currK]) {
                    tt.push_back(i);
                }
                sort(tt.begin(), tt.end(), std::greater<int>());
                if (cmp(tt, bestPath)) {
                    bestPath = tt;
                }
            }
            return;
        }

        if (!currN && !currK) {
            auto tt = tmpPath;
            sort(tt.begin(), tt.end(), std::greater<int>());
            if (cmp(tmpPath, bestPath)) {
                bestPath = tmpPath;
            }
            return;
        }

        if (currN > 0 && currK > 0) {
            for (int i = pow(currN, 1.0 / P) + 1; i > 0; i--) {
                tmpPath.push_back(i);
                dfs(currN - pow(i, P), currK - 1);
                tmpPath.pop_back();
            }
        }
    }

    void printPath(const vector<int> &p) {
        cout << N << " = ";
        for (int i = 0; i < p.size(); i++) {
            cout << p[i] << "^" << P;
            if (i != p.size() - 1) cout << " + ";
        }
        cout << endl;
    }

    int main() {
        cin >> N >> K >> P;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= K; j++) {
                bestPath.clear();
                tmpPath.clear();
                dfs(i, j);
                visited[i][j] = true;
                paths[i][j] = bestPath;
            }
        }
        if (paths[N][K].empty()) {
            cout << "Impossible" << endl;
        } else {
            printPath(paths[N][K]);
        }
        return 0;
    }
}
