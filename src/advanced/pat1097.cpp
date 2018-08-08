//
// Created by neild47 on 18-7-18.
//
#include <iostream>
#include <cmath>
#include <list>
#include <set>

using namespace std;
namespace pat1097 {

    struct Node {
        int addr, value, next;
    };

    Node nodes[100010];


    int main() {
        int head, N;
        cin >> head >> N;
        for (int i = 0; i < N; i++) {
            int addr0, value0, next0;
            scanf("%d%d%d", &addr0, &value0, &next0);
            nodes[addr0].addr = addr0;
            nodes[addr0].value = value0;
            nodes[addr0].next = next0;
        }

        list<Node> row;
        int iter = head;
        while (iter != -1) {
            row.push_back(nodes[iter]);
            iter = nodes[iter].next;
        }

        set<int> flags;

        list<Node> delNodes;

        for (auto item = row.begin(); item != row.end();) {
            if (flags.count(abs((*item).value))) {
                auto nextI = ++item;
                item--;
                delNodes.push_back(*item);
                row.erase(item);
                item = nextI;
            } else {
                flags.insert(abs((*item).value));
                item++;
            }
        }


        bool first = true;
        if (!row.empty()) {
            for (auto &n:row) {
                if (!first) printf("%05d\n", n.addr);
                printf("%05d %d ", n.addr, n.value);
                first = false;
            }
            cout << -1 << endl;
        }

        if (!delNodes.empty()) {
            first = true;
            for (auto &n:delNodes) {
                if (!first) printf("%05d\n", n.addr);
                printf("%05d %d ", n.addr, n.value);
                first = false;
            }
            cout << -1 << endl;
        }


        return 0;
    }
}
