//
// Created by neild47 on 18-7-20.
//
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>

namespace pat1100 {

    using namespace std;

    string gewei[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    string shiwei[] = {"zz", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

    int main() {
        map<string, int> geweiToDig, shiweiToDig;
        for (int i = 0; i < 13; i++) {
            geweiToDig[gewei[i]] = i;
        }
        for (int i = 1; i < 13; i++) {
            shiweiToDig[shiwei[i]] = i;
        }
        int n;
        cin >> n;
        string line;
        getline(cin, line);
        for (int i = 0; i < n; i++) {
            getline(cin, line);
            if (isdigit(line[0])) {
                stringstream ss(line);
                int num;
                ss >> num;
                int ge = num % 13;
                int shi = num / 13;
                if (shi != 0) {
                    cout << shiwei[shi];
                    if (ge != 0) cout << " ";
                }
                if (shi == 0 || ge != 0) {
                    cout << gewei[ge];
                }
                cout << endl;
            } else {
                stringstream ss(line);
                string s;
                ss >> s;
                int shi = 0;
                if (shiweiToDig.count(s)) {
                    shi = shiweiToDig[s] * 13;
                    ss >> s;
                }
                shi += geweiToDig[s];
                cout << shi << endl;
            }
        }
        return 0;
    }
}
