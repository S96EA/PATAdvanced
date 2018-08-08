//
// Created by neild47 on 18-6-1.
//
#include <iostream>
#include <algorithm>

using namespace std;
namespace pat1012 {


    struct Student {
        int id;
        int score[4];
        int rank[4];
    } students[2000];

    int idToIdx[1000000];

    char idxToChar[4] = {'A', 'C', 'M', 'E'};

    int main() {
        fill(idToIdx, idToIdx + 1000000, -1);
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            cin >> students[i].id >> students[i].score[1] >> students[i].score[2] >> students[i].score[3];
            students[i].score[0] = static_cast<int>(
                    (students[i].score[1] + students[i].score[2] + students[i].score[3]) / 3.0 + 0.5);
        }

        for (int ent = 0; ent < 4; ent++) {
            sort(students, students + n,
                 [ent](const Student &s1, const Student &s2) { return s1.score[ent] > s2.score[ent]; });
            students[0].rank[ent] = 1;
            for (int i = 1; i < n; i++) {
                students[i].rank[ent] = i + 1;
                if (students[i].score[ent] == students[i - 1].score[ent]) {
                    students[i].rank[ent] = students[i - 1].rank[ent];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            idToIdx[students[i].id] = i;
        }

        for (int p = 0; p < m; p++) {
            int id;
            cin >> id;
            int i = idToIdx[id];
            if (i == -1) {
                cout << "N/A" << endl;
                continue;
            }
//        cout << students[i].id << endl;

            int minRank = students[i].rank[0];
            int minIdx = 0;
            for (int r = 1; r < 4; r++) {
                if (students[i].rank[r] < minRank) {
                    minRank = students[i].rank[r];
                    minIdx = r;
                }
            }

            cout << minRank << " " << idxToChar[minIdx] << endl;
        }
        return 0;
    }
}
