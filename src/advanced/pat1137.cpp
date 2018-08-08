//
// Created by neild47 on 18-8-6.
//
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;
namespace pat1137 {


    struct student {
        string name;
        int p = -1, m = -1, n = -1, finalGrade;
    };

    bool cmp(const student *s1, const student *s2) {
        if (s1->finalGrade != s2->finalGrade) return s1->finalGrade > s2->finalGrade;
        return s1->name < s2->name;
    }

    int main() {
        int P, M, N;
        map<string, student *> nameToStudent;

        cin >> P >> M >> N;
        char buf[30];
        int v;
        for (int i = 0; i < P; i++) {
            scanf("%s%d", buf, &v);
            if (v < 200) {
                continue;
            }
            auto s = new student{};
            s->name = string(buf);
            s->p = v;
            nameToStudent.emplace(s->name, s);
        }

        for (int i = 0; i < M; i++) {
            scanf("%s%d", buf, &v);
            if (!nameToStudent.count(buf)) {
                continue;
            }

            nameToStudent[buf]->m = v;
        }

        for (int i = 0; i < N; i++) {
            scanf("%s%d", buf, &v);
            if (!nameToStudent.count(buf)) {
                continue;
            }

            nameToStudent[buf]->n = v;
        }

        vector<student *> ans;
        for (auto s:nameToStudent) {
            auto ss = s.second;
            if (ss->m > ss->n) {
                ss->finalGrade = (int) round(0.4 * ss->m + 0.6 * (ss->n == -1 ? 0 : ss->n));
            } else {
                ss->finalGrade = ss->n == -1 ? 0 : ss->n;
            }
            if (ss->finalGrade >= 60)
                ans.push_back(ss);
        }
        sort(ans.begin(), ans.end(), cmp);

        for (auto s:ans) {
            printf("%s %d %d %d %d\n", s->name.data(), s->p, s->m, s->n, s->finalGrade);
        }

        return 0;
    }

}
