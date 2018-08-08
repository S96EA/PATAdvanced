//
// Created by neild47 on 18-7-4.
//
#include <iostream>
#include <algorithm>
#include <vector>

namespace pat1080 {

    using namespace std;

    struct Application {
        int id;
        int fg, ge, gi;
        int choices[5];
        int rank;
        int admit = -1;
    };

    int quota[110];
    int N, M, K;
    vector<Application> applications;
    vector<int> admits[110];

    bool equ(const Application &app1, const Application &app2) {
        return app1.fg == app2.fg && app1.ge == app2.ge;
    };

    bool cmp(const Application &app1, const Application &app2) {
        if (app1.fg != app2.fg) return app1.fg > app2.fg;
        else return app1.ge > app2.ge;
    }

    void printV() {
        for (int i = 0; i < N; i++) {
            cout << applications[i].id << " " << applications[i].fg << " " << applications[i].ge << " "
                 << applications[i].gi << " **";
            for (int j = 0; j < K; j++) {
                cout << " " << applications[i].choices[j];
            }
            cout << endl;
        }
    }

    int main() {
        cin >> N >> M >> K;
        for (int i = 0; i < M; i++) {
            scanf("%d", quota + i);
        }

        Application a{};
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &a.ge, &a.gi);
            for (int j = 0; j < K; j++) {
                scanf("%d", &a.choices[j]);
            }
            a.id = i;
            a.fg = (a.ge + a.gi) / 2;
            applications.push_back(a);
        }

        sort(applications.begin(), applications.end(), cmp);
//    printV();

        applications[0].admit = applications[0].choices[0];
        quota[applications[0].choices[0]]--;
        admits[applications[0].choices[0]].push_back(applications[0].id);
        for (int i = 1; i < N; i++) {
            auto &app = applications[i];
            int prevAdmit = applications[i - 1].admit;
            auto &prev = applications[i - 1];
            for (int j = 0; j < K; j++) {
                int choice = app.choices[j];
                if (quota[choice] <= 0) {
                    if (choice == prevAdmit && equ(app, prev)) {
                        app.admit = choice;
                        admits[choice].push_back(app.id);
                        break;
                    }
                } else {
                    quota[choice]--;
                    app.admit = choice;
                    admits[choice].push_back(app.id);
                    break;
                }
            }
        }

        for (int i = 0; i < M; i++) {
            if (admits[i].empty()) {
                printf("\n");
                continue;
            }
            sort(admits[i].begin(), admits[i].end());
            for (int j = 0; j < admits[i].size(); j++) {
                if (j != 0) printf(" ");
                printf("%d", admits[i][j]);
            }
            if (i != M - 1) printf("\n");
        }
        return 0;
    }
}
