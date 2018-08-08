#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
namespace pat1077 {
    int main() {
        int n;
        cin >> n;
        string line;
        getline(cin, line);
        vector<string> lines;
        for (int i = 0; i < n; i++) {
            getline(cin, line);
            reverse(line.begin(), line.end());
            lines.push_back(line);
        }

        int i = 0;
        string postFix = "";
        for (;; i++) {
            if (i >= lines[0].size()) break;
            char c = lines[0][i];
            bool isEq = true;
            for (auto &s:lines) {
                if (s[i] != c) {
                    isEq = false;
                    break;
                }
            }
            if (!isEq) break;
            postFix += c;
        }
        reverse(postFix.begin(), postFix.end());
        if (i == 0) {
            cout << "nai" << endl;
        } else {
            cout << postFix << endl;
        }
        return 0;
    }
}