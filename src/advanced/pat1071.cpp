//
// Created by neild47 on 18-6-29.
//

#include <iostream>
#include <map>

namespace pat1072 {

    using namespace std;

    int main() {
        string line;
        getline(cin, line);
        line += "\n";
        char buf[80];
        int iter = 0;
        int slen = line.size();
        bool isLex = false;
        map<string, int> counts;
        for (int i = 0; i < slen; i++) {
            char c = line[i];
            bool isWordLetter = (isalpha(c) || isdigit(c));
            if (!isLex && isWordLetter) {
                isLex = true;
            }

            if (isLex) {
                if (isWordLetter) {
                    if (isupper(c)) {
                        buf[iter++] = (char) tolower(c);
                    } else {
                        buf[iter++] = c;
                    }
                } else {
                    isLex = false;
                    buf[iter] = '\0';
                    iter = 0;
                    counts[buf]++;
                }
            }
        }

        string maxS;
        int maxC = -1;
        for (auto &item:counts) {
            if (item.second > maxC) {
                maxC = item.second;
                maxS = item.first;
            }
        }
        cout << maxS << " " << maxC << endl;
        return 0;
    }
}
