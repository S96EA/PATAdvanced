//
// Created by neild47 on 18-8-8.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

namespace pat1145 {

    int MSize, N, M;

    int isPrime(int n) {
        if (n <= 1) return false;
        int sq = sqrt(MSize);
        for (int i = 2; i <= sq; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    void resizeMSize() {
        while (!isPrime(MSize)) {
            MSize++;
        }
    }

    vector<int> hashTable;

    bool insert(int value) {
        int hashCode = value % MSize;
        for (int i = 1; i < MSize && hashTable[hashCode]; i++) {
            hashCode = (value + i * i) % MSize;
        }
        if (!hashTable[hashCode]) {
            hashTable[hashCode] = value;
            return true;
        }
        return false;
    }

    int find(int value) {
        int cnt = 1;
        int hashCode;
        for (int i = 0; i < MSize; i++, cnt++) {
            hashCode = (value + i * i) % MSize;
            if (!hashTable[hashCode] || hashTable[hashCode] == value) break;
        }
        return cnt;

    }

    int main() {
        cin >> MSize >> N >> M;
        resizeMSize();
        hashTable.resize(MSize, 0);

        for (int i = 0; i < N; i++) {
            int v;
            scanf("%d", &v);
            if (!insert(v)) {
                printf("%d cannot be inserted.\n", v);
            }
        }

        double s = 0;
        for (int i = 0; i < M; i++) {
            int v;
            scanf("%d", &v);
            s += find(v);
        }
        printf("%.1f\n", s / M);
        return 0;
    }

}
