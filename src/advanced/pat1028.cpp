//
// Created by neild47 on 18-6-7.
//
#include <iostream>
#include <vector>
#include <algorithm>

/*
 *
 * cin的速度比较慢，测试的用例数量比较大，因此尽量使用scanf代替cin，否则可能超时
 *
 * */

using namespace std;
namespace pat1028 {

    struct Student {
        int id, grade;
        string name;

        Student(int id, string name, int grade) : id(id), name(std::move(name)), grade(grade) {}

        Student() {}
    };

    bool cmpById(const Student *s1, const Student *s2) {
        return s1->id < s2->id;
    }

    bool cmpByName(const Student *s1, const Student *s2) {
        if (s1->name != s2->name) { return s1->name < s2->name; }
        else return s1->id < s2->id;
    }

    bool cmpByGrade(const Student *s1, const Student *s2) {
        if (s1->grade != s2->grade) { return s1->grade < s2->grade; }
        else return s1->id < s2->id;
    }


    int main() {
        int n, c;
        cin >> n >> c;
        vector<Student *> students;
        for (int i = 0; i < n; i++) {
            auto s = new Student();
            auto name = new char[20];
            scanf("%d %s %d", &s->id, name, &s->grade);
            s->name = name;
            students.push_back(s);
        }
        if (c == 1) {
            sort(students.begin(), students.end(), cmpById);
        } else if (c == 2) {
            sort(students.begin(), students.end(), cmpByName);
        } else {
            sort(students.begin(), students.end(), cmpByGrade);
        }

        for (auto s:students) {
            printf("%06d %s %d\n", s->id, s->name.data(), s->grade);
        }
        return 0;
    }
}
