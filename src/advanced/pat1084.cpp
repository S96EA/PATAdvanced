//
// Created by neild47 on 18-7-11.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
namespace pat1084 {
    bool broken[510];

    int main() {
        string l1, l2;
        cin >> l1 >> l2;
        auto i1 = l1.begin(), i2 = l2.begin();
        vector<char> ans;
        while (i1 != l1.end()) {
            if (i2 == l2.end() || *i1 != *i2) {
                char c = *i1;
                if (islower(*i1)) {
                    c = (char) toupper(c);
                }
                if (!broken[c]) {
                    broken[c] = true;
                    ans.push_back(c);
                }
                i1++;
            } else {
                i1++, i2++;
            }
        }
        for (char c:ans) {
            cout << c;
        }
        return 0;
    }
}
