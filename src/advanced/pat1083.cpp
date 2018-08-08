//
// Created by neild47 on 18-7-10.
//
#include <iostream>
#include <vector>

using namespace std;
namespace pat1083 {
    struct Student {
        string name, id;
    };

    Student *grades[110];

    int main() {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            Student *student = new Student{};
            int grade;
            cin >> student->name >> student->id >> grade;
            grades[grade] = student;
        }

        int grade1, grade2;
        cin >> grade1 >> grade2;

        vector<Student *> ans;
        for (int i = grade2; i >= grade1; i--) {
            if (grades[i]) {
                ans.push_back(grades[i]);
            }
        }
        if (ans.empty()) {
            cout << "NONE" << endl;
        } else {
            for (auto &s:ans) {
                cout << s->name << " " << s->id << endl;
            }
        }
        return 0;
    }
}
