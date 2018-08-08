//
// Created by neild47 on 18-6-13.
//
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

namespace pat1047 {

    using namespace std;

    int main() {
        int numStudents, numCourses;
        map<int, vector<string>> courseToStudents;
        cin >> numStudents >> numCourses;
        char name[5];
        for (int i = 0; i < numStudents; i++) {
            int n, c;
            scanf("%s %d", name, &n);
            for (int j = 0; j < n; j++) {
                scanf("%d", &c);
                courseToStudents[c].push_back(name);
            }
        }

        for (int i = 1; i <= numCourses; i++) {
            if (!courseToStudents.count(i)) {
                cout << i << " 0" << endl;
                continue;
            }
            auto item = courseToStudents[i];
            cout << i << " " << item.size() << endl;
            sort(item.begin(), item.end());
            for (auto &na:item) {
                cout << na << endl;
            }
        }
        return 0;
    }
}
