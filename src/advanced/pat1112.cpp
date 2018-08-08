//
// Created by neild47 on 18-7-31.
//
#include <iostream>
#include <map>
#include <vector>

using namespace std;
namespace pat1112 {
    bool vis[256];

    int main() {
        int k;
        string s;
        cin >> k >> s;
        map<char, int> ansC;
        vector<int> ansS;
        for (int i = 0; i < s.size();) {
            int cnt = 1;
            int c = s[i];
            i++;
            while (i < s.size() && s[i] == c) {
                i++, cnt++;
            }
            if (cnt % k == 0 && ansC[c] == 0) {
                ansC[c] = 1;
                ansS.push_back(c);
            } else if (cnt % k != 0) {
                ansC[c] = -1;
            }
        }

        for (auto c:ansS) {
            if (!vis[c] && ansC[c] == 1) {
                vis[c] = true;
                printf("%c", c);
            }
        }
        printf("\n");
        for (int i = 0; i < s.size();) {
            printf("%c", s[i]);
            if (ansC[s[i]] == 1) {
                i += k;
            } else {
                i++;
            }
        }
        return 0;
    }
}
