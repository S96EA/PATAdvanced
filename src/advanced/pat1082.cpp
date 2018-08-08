//
// Created by neild47 on 18-7-10.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;
namespace pat1082 {

#define YI 100000000
#define WAN 10000
#define QIAN 1000

    string numberToString[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    string wei[] = {"Qian", "Bai", "Shi", ""};

    string getT(int n, bool needLing) {
        int b[] = {1000, 100, 10, 1};
        vector<string> ans;
        for (int i = 0; i < 4 && n > 0; i++) {
            if (n >= b[i]) {
                ans.push_back(numberToString[n / b[i]]);
                if (wei[i] != "")
                    ans.push_back(wei[i]);
                n %= b[i];
                needLing = true;
            } else {
                if (needLing) {
                    ans.emplace_back("ling");
                    needLing = false;
                }
            }
        }
        string ret;
        for (int i = 0; i < ans.size(); i++) {
            if (i != 0) ret += " ";
            ret += ans[i];
        }
        return ret;
    }

    int main() {
        int number;
        bool needLing = false;
        cin >> number;
        if (number == 0) {
            printf("ling");
            return 0;
        }

        if (number < 0) {
            number = -number;
            printf("Fu ");
        }
        if (number >= YI) {
            int yi = number / YI;
            cout << numberToString[yi] << " Yi ";
            number %= YI;
            needLing = true;
        }

        if (number >= WAN) {
            cout << getT(number / WAN, needLing) << " Wan ";
            number %= WAN;
            needLing = true;
        } else {
            needLing = false;
        }

        cout << getT(number, needLing);

        return 0;
    }
}
