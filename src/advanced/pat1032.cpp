//
// Created by neild47 on 18-6-8.
//

#include <iostream>

using namespace std;

namespace pat1032 {


    char Value[100000];
    int Next[100000];

    int head1, head2;

    int main() {
        int n;
        cin >> head1 >> head2 >> n;
        for (int i = 0; i < n; i++) {
            int addr, next;
            char c;
            scanf("%d %c %d", &addr, &c, &next);
            Value[addr] = c;
            Next[addr] = next;
        }

        int len1 = 0, iter = head1;
        while (iter != -1) {
            iter = Next[iter];
            len1++;
        }
        int len2 = 0;
        iter = head2;
        while (iter != -1) {
            iter = Next[iter];
            len2++;
        }

        int iter1 = head1, iter2 = head2;
        int dis = len1 - len2;
        if (dis < 0) {
            dis = -dis;
            while (dis > 0) {
                iter2 = Next[iter2];
                dis--;
            }
        } else {
            while (dis > 0) {
                iter1 = Next[iter1];
                dis--;
            }
        }

        while (iter1 != -1 && iter2 != -1 && iter1 != iter2) {
            iter1 = Next[iter1];
            iter2 = Next[iter2];
        }

        if (min(iter1, iter2) == -1) {
            cout << -1 << endl;
        } else {
            printf("%05d\n", iter1);
        }
        return 0;
    }
}
