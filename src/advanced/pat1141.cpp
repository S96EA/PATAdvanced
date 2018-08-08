//
// Created by neild47 on 18-8-7.
//
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>

using namespace std;
namespace pat1141 {

    struct school {
        string name;
        int n;
        int score[3];
        int tws = 0;

        school() : score{0}, n{0} {}
    };

    bool cmp(const school &s1, const school &s2) {
        if (s1.tws != s2.tws) return s1.tws > s2.tws;
        if (s1.n != s2.n) return s1.n < s2.n;
        return s1.name < s2.name;
    }

    int getHash(char *s) {
        int hash = 0;
        while (*s != 0) {
            if (isupper(*s)) {
                hash = hash * 26 + *s - 'A';
            } else {
                hash = hash * 26 + *s - 'a';
            }
            s++;
        }
        return hash;
    };

    int main() {
        map<char, int> cToIdx;
        map<int, school> schools;

        cToIdx.emplace('B', 0);
        cToIdx.emplace('A', 1);
        cToIdx.emplace('T', 2);

        int n;
        cin >> n;
        char id[10], ins[10];
        int v;
        for (int i = 0; i < n; i++) {
            scanf("%s%d%s", id, &v, ins);
            school &sc = schools[getHash(ins)];
            if (sc.n == 0) {
                int len = strlen(ins);
                for (int j = 0; j < len; j++) {
                    ins[j] = tolower(ins[j]);
                }
                sc.name = string(ins);
            }
            sc.n++;
            sc.score[cToIdx[id[0]]] += v;
        }

        vector<school> ans;
        for (auto &item:schools) {
            school &sc = item.second;
            sc.tws = sc.score[0] / 1.5 + sc.score[1] + sc.score[2] * 1.5;
            ans.push_back(sc);
        }

        sort(ans.begin(), ans.end(), cmp);

        cout << ans.size() << endl;
        int rank = 1;
        for (int i = 0; i < ans.size(); i++) {
            if (i == 0 || ans[i].tws == ans[i - 1].tws) {
            } else {
                rank = i + 1;
            }
            printf("%d %s %d %d\n", rank, ans[i].name.data(), ans[i].tws, ans[i].n);
        }
        return 0;
    }
}
