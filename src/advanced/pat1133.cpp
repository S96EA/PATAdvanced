//
// Created by neild47 on 18-8-4.
//
#include <iostream>
#include <vector>

using namespace std;
namespace pat1133 {
    struct node {
        int addr, value, next;
    };

    node list0[100010];

    int main() {
        int first, n, k, addr0;
        cin >> first >> n >> k;
        for (int i = 0; i < n; i++) {
            scanf("%d", &addr0);
            node &node1 = list0[addr0];
            node1.addr = addr0;
            scanf("%d%d", &node1.value, &node1.next);
        }

        vector<node *> neg, ink, other;

        while (first != -1) {
            node *node1 = &list0[first];
            if (node1->value < 0) {
                neg.push_back(node1);
            } else if (node1->value > k) {
                other.push_back(node1);
            } else {
                ink.push_back(node1);
            }
            first = node1->next;
        }
        for (auto no:ink) neg.push_back(no);
        for (auto no:other) neg.push_back(no);

        for (int i = 0; i < neg.size(); i++) {
            if (i) {
                printf(" %05d\n", neg[i]->addr);
            }
            printf("%05d %d", neg[i]->addr, neg[i]->value);
        }
        printf(" -1\n");
        return 0;
    }
}
