//
// Created by neild47 on 18-6-22.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace pat1062 {

    struct People {
        int id, virtue, talent;
    };

    int N, L, H;

    bool cmp(const People &p1, const People &p2) {
        int tot1 = p1.virtue + p1.talent;
        int tot2 = p2.virtue + p2.talent;
        if (tot1 != tot2) return tot1 > tot2;
        else if (p1.virtue != p2.virtue) return p1.virtue > p2.virtue;
        else return p1.id < p2.id;
    }

    int main() {
        cin >> N >> L >> H;
        People p{};
        vector<vector<People>> peoples(4);
        int cnt{};
        for (int i = 0; i < N; i++) {
            scanf("%d%d%d", &p.id, &p.virtue, &p.talent);
            if (p.virtue < L || p.talent < L) continue;
            if (p.virtue >= H && p.talent >= H) peoples[0].push_back(p);
            else if (p.virtue >= H && p.talent < H) peoples[1].push_back(p);
            else if (p.virtue < H && p.talent < H && p.virtue >= p.talent) peoples[2].push_back(p);
            else peoples[3].push_back(p);
            cnt++;
        }

        for (auto &item:peoples) {
            sort(item.begin(), item.end(), cmp);
        }
        cout << cnt << endl;

        for (auto &item:peoples) {
            for (auto &pe:item) {
                printf("%08d %d %d\n", pe.id, pe.virtue, pe.talent);
            }
        }

        return 0;
    }
}
