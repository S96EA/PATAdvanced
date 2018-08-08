//
// Created by neild47 on 18-8-3.
//
#include <iostream>
#include <set>

using namespace std;

namespace pat1129 {

    int times[50010];

    struct cmp {
        bool operator()(const int &n1, const int &n2) const {
            if (times[n1] != times[n2]) return times[n1] > times[n2];
            return n1 < n2;
        }
    };

    int N, K;

    int main() {
        cin >> N >> K;
        set<int, cmp> entries;
        int v;
        scanf("%d", &v);
        times[v]++;
        entries.insert(v);
        for (int i = 1; i < N; i++) {
            scanf("%d", &v);
            printf("%d:", v);
            auto r = entries.begin();
            while (r != entries.end()) {
                printf(" %d", *r++);
            }
            printf("\n");
            if (entries.count(v)) {
                entries.erase(v);
                times[v]++;
                entries.insert(v);
            } else {
                times[v]++;
                if (entries.size() < K) {
                    entries.insert(v);
                } else {
                    auto e = entries.rbegin();
                    if (times[v] > times[*e] || (times[v] == times[*e] && v < *e)) {
                        entries.erase(*e);
                        entries.insert(v);
                    }
                }
            }
        }

        return 0;
    }
}
