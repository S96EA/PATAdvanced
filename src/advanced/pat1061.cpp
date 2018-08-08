//
// Created by neild47 on 18-6-22.
//

#include <iostream>
#include <vector>

using namespace std;

namespace pat1061 {


    vector<string> pos2WeekDay{"HelloWorld", "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

    int main() {
        string s1, s2, s3, s4;
        cin >> s1 >> s2 >> s3 >> s4;
        int i = 0;
        int date[10];
        bool getWeek = false;
        for (; i < s1.size() && i < s2.size(); i++) {
            if (!getWeek && s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G') {
                date[0] = s1[i] - 'A' + 1;
                getWeek = true;
            } else if (getWeek && s1[i] == s2[i] && (s1[i] >= '0' && s1[i] <= '9' || s1[i] >= 'A' && s1[i] <= 'N')) {
                if (isdigit(s1[i])) {
                    date[1] = s1[i] - '0';
                } else {
                    date[1] = s1[i] - 'A' + 10;
                }
                break;
            }
        }

        for (i = 0; i < s3.size() && i < s4.size(); i++) {
            if (s3[i] == s4[i] && isalpha(s3[i])) {
                date[2] = i;
                break;
            }
        }

        printf("%s %02d:%02d\n", pos2WeekDay[date[0]].c_str(), date[1], date[2]);

        return 0;
    }
}
