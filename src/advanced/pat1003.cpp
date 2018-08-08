//
// Created by neild47 on 18-5-27.
//
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <set>

/**
 * 这道题一开始做的时候卡了很长的时间，如果不看解析都不会做对
 * 问题在于审题没有审清楚，看题目描述的时候没有看明白
 * 题目说的很清楚： the number of different shortest paths between C1 and C2， 不同的最短路径的数目
 * 但是我输出的是最短路径的长度，这肯定是不行的
 * */

using namespace std;
namespace pat1003 {

    int numHands[501];
    int dis[501];
    int hands[501];

    struct edge {
        int s, e, l, h;

        edge(int s, int e, int l, int h) : s(s), e(e), l(l), h(h) {}

        friend ostream &operator<<(ostream &ostream1, const edge &edge1) {
            ostream1 << edge1.s << " " << edge1.e << " " << edge1.l;
            return ostream1;
        }

        friend bool operator>(const edge &e1, const edge &e2) {
            if (e1.l != e2.l) {
                return e1.l > e2.l;
            } else {
                return e1.h < e2.h;
            }
        }
    };

    vector<edge> links[501];


    int main() {
        fill(dis, dis + 501, INT32_MAX);
        int n, m, s, d;
        cin >> n >> m >> s >> d;
        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            numHands[i] = value;
        }
        for (int i = 0; i < m; i++) {
            int s, e, l;
            cin >> s >> e >> l;
            links[s].emplace_back(s, e, l, 0);
            links[e].emplace_back(e, s, l, 0);
        }
        priority_queue<edge, vector<edge>, greater<edge>> queue1;
        set<int> already;
        dis[s] = 0;
        queue1.emplace(s, s, 0, numHands[s]);
        int count = 0;
        while (!queue1.empty()) {
            auto e = queue1.top();
            queue1.pop();
            int end = e.e;
            if (e.l < dis[e.e]) {
                count = 1;
                dis[e.e] = e.l;
                hands[e.e] = e.h;
            } else if (e.l == dis[e.e]) {
                if (e.e == d) {
                    count++;
                }
                if (e.h > hands[e.e]) {
                    hands[e.e] = e.h;
                }
            }
            already.insert(end);

            for (const auto &nexte:links[end]) {
                if (!already.count(nexte.e)) {
                    queue1.emplace(s, nexte.e, e.l + nexte.l, e.h + numHands[nexte.e]);
                }
            }
        }
        cout << count << " " << hands[d] << endl;
        return 0;
    }
//    for (int i = 0; i < n; i++) {
//        cout << i << " " << numHands[i] << endl;
//    }
//    for (int i = 0; i < n; i++) {
//        for (auto e:links[i]) {
//            cout << e << endl;
//        }
//        cout << endl;
//    }
}
