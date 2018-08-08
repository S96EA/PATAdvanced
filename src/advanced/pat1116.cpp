//
// Created by neild47 on 18-8-1.
//
#include <iostream>
#include <algorithm>

using namespace std;
namespace pat1116 {
    bool primes[11000];

    void getPrimes() {
        fill(primes, primes + 11000, true);
        primes[0] = primes[1] = false;
        for (int i = 0; i < 11000; i++) {
            if (primes[i]) {
                int t = i + i;
                while (t < 11000) {
                    primes[t] = false;
                    t += i;
                }
            }
        }
    }

    int idToRank[11000];

    int main() {
        getPrimes();
        fill(idToRank, idToRank + 11000, -1);
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int v;
            scanf("%d", &v);
            idToRank[v] = i + 1;
        }

        int k;
        cin >> k;
        for (int i = 0; i < k; i++) {
            int id;
            scanf("%d", &id);
            printf("%04d: ", id);
            if (idToRank[id] == -1) {
                printf("Are you kidding?\n");
            } else if (idToRank[id] == 0) {
                printf("Checked\n");
            } else {
                if (idToRank[id] == 1) {
                    printf("Mystery Award\n");
                } else if (primes[idToRank[id]]) {
                    printf("Minion\n");
                } else {
                    printf("Chocolate\n");
                }
                idToRank[id] = 0;
            }
        }

        return 0;
    }
}
