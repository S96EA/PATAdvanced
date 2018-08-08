//
// Created by neild47 on 18-6-19.
//
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

namespace pat1055 {
    struct Person {
        char *name;
        int age, worth;
    };

    bool cmp(const Person *p1, const Person *p2) {
        if (p1->worth != p2->worth) return p1->worth > p2->worth;
        if (p1->age != p2->age) return p1->age < p2->age;
        return strcmp(p1->name, p2->name) < 0;
    }

    int main() {
        int n, k;
        cin >> n >> k;
        vector<Person *> persons;
        persons.reserve(n);
        int age, worth;
        for (int i = 0; i < n; i++) {
            char *name = new char[10];
            scanf("%s%d%d", name, &age, &worth);
            persons.push_back(new Person{name, age, worth});
        }
        sort(persons.begin(), persons.end(), cmp);

        int m, amin, amax;
        for (int i = 0; i < k; i++) {
            scanf("%d%d%d", &m, &amin, &amax);
            printf("Case #%d:\n", i + 1);
            int cnt = 0;
            for (auto item:persons) {
                if (item->age >= amin && item->age <= amax) {
                    cout << item->name << " " << item->age << " " << item->worth << endl;
                    cnt++;
                }
                if (cnt == m) break;
            }
            if (cnt == 0) cout << "None" << endl;
        }
        return 0;
    }
}
