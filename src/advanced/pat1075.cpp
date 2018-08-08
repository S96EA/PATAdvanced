//
// Created by neild47 on 18-7-1.
//
#include <iostream>
#include <algorithm>
#include <vector>

namespace pat1075 {

    using namespace std;

    struct Mark {
        int marks[10];
        bool passFlag = false;
        int sumMarks;
        int id;
        int perfectCnt = 0;

        Mark() {
            fill(marks, marks + 10, -2);
        }
    };

    int problemMarks[10];
    int N, K, M;
    Mark players[100010];

    void printM(const Mark *mark, int rank) {
        printf("%d %05d %d", rank, mark->id, mark->sumMarks);
        for (int i = 1; i <= K; i++) {
            printf(" ");
            if (mark->marks[i] == -2) {
                printf("-");
            } else {
                if (mark->marks[i] == -1) {
                    printf("0");
                } else {
                    printf("%d", mark->marks[i]);
                }
            }
        }
        printf("\n");
    }

    int main() {
        cin >> N >> K >> M;
        for (int i = 1; i <= K; i++) {
            scanf("%d", &problemMarks[i]);
        }

        vector<Mark *> ans;
        for (int i = 0; i < M; i++) {
            int id, pid, mark;
            scanf("%d%d%d", &id, &pid, &mark);
            if (!players[id].passFlag && mark >= 0) {
                players[id].passFlag = true;
                players[id].id = id;
                ans.push_back(&players[id]);
            }
            if (mark > players[id].marks[pid]) {
                players[id].marks[pid] = mark;
            }
        }

        for (auto &p:ans) {
            p->sumMarks = 0;
            p->perfectCnt = 0;
            for (int i = 1; i <= K; i++) {
                if (p->marks[i] >= 0) {
                    p->sumMarks += p->marks[i];
                    if (p->marks[i] == problemMarks[i]) {
                        (p->perfectCnt)++;
                    }
                }
            }
        }

        sort(ans.begin(), ans.end(), [](const Mark *p1, const Mark *p2) {
                 if (p1->sumMarks != p2->sumMarks)
                     return p1->sumMarks > p2->sumMarks;
                 else if (p1->perfectCnt != p2->perfectCnt) {
                     return p1->perfectCnt > p2->perfectCnt;
                 } else {
                     return p1->id < p2->id;
                 }
             }
        );
        int rank = 1;
        printM(ans[0], rank);
        for (int i = 1; i < ans.size(); i++) {
            if (ans[i]->sumMarks != ans[i - 1]->sumMarks) {
                rank = i + 1;
            }
            printM(ans[i], rank);
        }
        return 0;
    }
}
