//
// Created by neild47 on 18-7-30.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
namespace pat1109 {


    struct people {
        string name;
        int height;

        people(string name, int height) : name(name), height(height) {}


        friend bool operator<(const people &p1, const people &p2) {
            if (p1.height != p2.height) return p1.height > p2.height;
            return p1.name < p2.name;
        }
    };

    int K, N;

    int main() {
        string s;
        int h;
        cin >> N >> K;
        vector<people> peoples;
        vector<vector<people *>> ans;
        for (int i = 0; i < N; i++) {
            cin >> s >> h;
            if (h >= 30 && h <= 300)
                peoples.emplace_back(s, h);
        }
        sort(peoples.begin(), peoples.end());
//    for (auto p:peoples) {
//        cout << p.name << " " << p.height << endl;
//    }

        auto iterP = peoples.begin();
        for (int i = 0; i < K; i++) {
            int nRow = N / K;
            if (i == 0) {
                nRow += N % K;
            }
            vector<people *> row(nRow);
            int midPos = nRow / 2;
            row[midPos] = iterP++.base();
            int step = 1;
            while (midPos - step >= 0) {
                row[midPos - step] = iterP++.base();
                if (midPos + step < nRow) {
                    row[midPos + step] = iterP++.base();
                } else {
                    break;
                }
                step++;
            }
            ans.push_back(row);
        }

        for (auto &r:ans) {
            for (int i = 0; i < r.size(); i++) {
                if (i != 0) printf(" ");
                printf("%s", r[i]->name.data());
            }
            printf("\n");
        }
        return 0;
    }

}
