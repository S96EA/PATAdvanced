//
// Created by neild47 on 18-5-27.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
namespace pat1002 {
    struct terms {
        int exponent;
        double coefficient;

        terms(int e, double co) {
            this->exponent = e;
            this->coefficient = co;
        }

        bool operator<(const terms &other) {
            return other.exponent < this->exponent;
        }

        friend bool operator==(const terms &p1, const terms &p2) {
            return p1.exponent == p2.exponent;
        }
    };

    void readP(vector<terms> &p) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int e;
            double co;
            cin >> e >> co;
            p.emplace_back(e, co);
        }
        sort(p.begin(), p.end());
    }

    void sumP(const vector<terms> &p1, const vector<terms> &p2, vector<terms> &out) {
        auto iterP1 = p1.begin();
        auto iterP2 = p2.begin();
        while (iterP1 != p1.end() && iterP2 != p2.end()) {
            if ((*iterP1) == (*iterP2)) {
                double co = ((*iterP1).coefficient + (*iterP2).coefficient);
                if (co != 0) {
                    out.emplace_back((*iterP1).exponent, co);
                }
                iterP1++;
                iterP2++;
            } else if ((*iterP1).exponent < (*iterP2).exponent) {
                out.push_back(*iterP2);
                iterP2++;
            } else {
                out.push_back(*iterP1);
                iterP1++;
            }
        }
        while (iterP1 != p1.end()) {
            out.push_back(*iterP1);
            iterP1++;
        }
        while (iterP2 != p2.end()) {
            out.push_back(*iterP2);
            iterP2++;
        }
        sort(out.begin(), out.end());
    }


    int main() {
        vector<terms> p1;
        vector<terms> p2;
        vector<terms> s;

        readP(p1);
        readP(p2);

        sumP(p1, p2, s);
        printf("%d", s.size());
        for (auto &term:s) {
            printf(" %d %.1f", term.exponent, term.coefficient);
        }
        return 0;
    }
}
