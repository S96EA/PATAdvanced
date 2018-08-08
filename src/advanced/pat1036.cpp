//
// Created by neild47 on 18-6-10.
//
#include <iostream>

using namespace std;

namespace pat1036 {

    int main() {
        int lowestMaleGrade = INT32_MAX, highestFemaleGrade = INT32_MIN, n;
        string lowestMaleName, lowestMaleId, highestFemaleName, highestFemaleId;
        string name, gender, id;
        int grade;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> name >> gender >> id >> grade;
            if (gender[0] == 'M' && grade < lowestMaleGrade) {//male
                lowestMaleGrade = grade;
                lowestMaleId = id;
                lowestMaleName = name;
            } else if (gender[0] == 'F' && grade > highestFemaleGrade) {//female
                highestFemaleGrade = grade;
                highestFemaleName = name;
                highestFemaleId = id;
            }
        }

        if (highestFemaleGrade == INT32_MIN) cout << "Absent" << endl;
        else cout << highestFemaleName << " " << highestFemaleId << endl;

        if (lowestMaleGrade == INT32_MAX) cout << "Absent" << endl;
        else cout << lowestMaleName << " " << lowestMaleId << endl;

        if (lowestMaleGrade == INT32_MAX || highestFemaleGrade == INT32_MIN) cout << "NA" << endl;
        else cout << highestFemaleGrade - lowestMaleGrade << endl;

        return 0;
    }
}
