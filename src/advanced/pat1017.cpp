//
// Created by neild47 on 18-6-2.
//
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

namespace pat1017 {
    using namespace std;

    struct Person {
        int arriveTime, serveTime;

        Person() {}

        Person(int arriveTime, int serveTime) : arriveTime(arriveTime), serveTime(serveTime) {}
    };

    Person *newPerson(int a, int s) {
        return new Person(a, s);
    }

    const int START_TIME = 8 * 3600;
    const int END_TIME = 17 * 3600 + 1;

    int popTime[101];

    int main() {
        fill(popTime, popTime + 101, START_TIME);

        int n, k;
        cin >> n >> k;
        deque<Person *> persons;
        for (int i = 0; i < n; i++) {
            int h, m, s, t;
            scanf("%d:%d:%d", &h, &m, &s);
            cin >> t;
            if (t > 60) {
                t = 60;
            }
            int arriveTime = h * 3600 + m * 60 + s;
            if (arriveTime >= END_TIME) {
                continue;
            }
            auto person = newPerson(arriveTime, t * 60);
            persons.push_back(person);
        }
        sort(persons.begin(), persons.end(),
             [](const Person *p1, const Person *p2) { return p1->arriveTime < p2->arriveTime; });

        long sumWait = 0;
        int size = persons.size();
        while (!persons.empty()) {
            int w = min_element(popTime, popTime + k) - popTime;
//        if (popTime[w] >= END_TIME) {
//            break;
//        }

            auto p = persons.front();
            persons.pop_front();

            if (popTime[w] > p->arriveTime) {
                sumWait += popTime[w] - p->arriveTime;
            } else {
                popTime[w] = p->arriveTime;
            }
            popTime[w] += p->serveTime;
        }

        if (size == 0) {
            printf("0.0\n");
        } else {
            printf("%.1f\n", sumWait / 60.0 / size);
        }

        return 0;
    }
}
