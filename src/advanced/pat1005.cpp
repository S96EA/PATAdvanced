//
// Created by neild47 on 18-5-29.
//

#include <iostream>
#include <vector>

using namespace std;

namespace pat1005 {

    string intToString[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    int main() {
        string s;
        cin >> s;
        int sum = 0;
        for (auto c:s) {
            sum += c - '0';
        }
        vector<string> out;
        s = to_string(sum);
        for (auto c:s) {
            out.push_back(intToString[c - '0']);
        }

        auto item = out.begin();
        cout << *item;
        while (++item != out.end()) {
            cout << " " << *item;
        }
        return 0;
    }
}

