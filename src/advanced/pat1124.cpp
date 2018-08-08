//
// Created by neild47 on 18-8-2.
//

#include <iostream>
#include <set>
#include <vector>

using namespace std;
namespace pat1124 {
    int main() {
        int M, N, S;
        cin >> M >> N >> S;
        int cnt = 1;
        set<string> names;
        vector<string> ans;
        bool first = true;
        for (int i = 0; i < M; i++) {
            string s;
            cin >> s;
            if ((first && cnt == S) || (!first && cnt == N)) {
                if (names.count(s)) {
                    cnt--;
                } else {
                    if (first) first = false;
                    cnt = 0;
                    names.insert(s);
                    ans.push_back(s);
                }
            }
            cnt++;
        }

        if (ans.empty()) {
            cout << "Keep going..." << endl;
        } else {
            for (auto &s:ans) {
                cout << s << endl;
            }
        }
        return 0;
    }
}
