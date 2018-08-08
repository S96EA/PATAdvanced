//
// Created by neild47 on 18-7-3.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
namespace pat1078 {

#define TABLE_SIZE 10050

    bool primeTable[TABLE_SIZE];

    void setPrimeTable() {
        fill(primeTable, primeTable + TABLE_SIZE, true);
        primeTable[1] = false;
        for (int i = 2; i < TABLE_SIZE; i++) {
            if (primeTable[i]) {
                int tmp = i + i;
                while (tmp < TABLE_SIZE) {
                    primeTable[tmp] = false;
                    tmp += i;
                }
            }
        }
    }


    bool isPrime(int number) {
        return primeTable[number];
    }

    int hashTable[TABLE_SIZE];

    int MSize, N;

    int insert(int number) {
        int key = number % MSize;
        if (hashTable[key] == -1) {
            hashTable[key] = number;
            return key;
        }
        for (int iter = 1; iter < MSize; iter++) {
            int pos = (key + iter * iter) % MSize;
            if (hashTable[pos] == -1) {
                hashTable[pos] = number;
                return pos;
            }
        }
        return -1;
    }

    int main() {
        setPrimeTable();
        fill(hashTable, hashTable + TABLE_SIZE, -1);
        cin >> MSize >> N;
        while (!isPrime(MSize)) {
            MSize++;
        }

        int value;
        vector<int> ans;
        for (int i = 0; i < N; i++) {
            scanf("%d", &value);
            int pos = insert(value);
            ans.push_back(pos);
        }

        for (int i = 0; i < ans.size(); i++) {
            if (i != 0) printf(" ");
            if (ans[i] == -1) printf("-");
            else printf("%d", ans[i]);
        }
        return 0;
    }
}
