//
// Created by neild47 on 18-6-11.
//
#include <iostream>
#include <vector>

using namespace std;

namespace pat1040 {
    int main() {
        vector<char> chars;
        chars.reserve(2100);
        chars.push_back(0);
        char c;
        while ((c = (char) getchar()) && c != '\n') {
            chars.push_back(c);
            chars.push_back(0);
        }

        int longestSymmetricSize = -1;
        int ssize = (int) chars.size();
        for (int i = 0; i < ssize; i++) {
            if (chars[i]) {
                int k = 1;
                while (i - k >= 0 && i + k < ssize && chars[i - k] == chars[i + k]) { k++; }
                k = (k / 2) * 2 - 1;
                if (longestSymmetricSize < k) longestSymmetricSize = k;
            } else {
                int k = 1;
                while (i - k >= 0 && i + k < ssize && chars[i - k] == chars[i + k]) { k++; }
                k = (k / 2) * 2;
                if (longestSymmetricSize < k) longestSymmetricSize = k;
            }
        }
        cout << longestSymmetricSize << endl;

//    for (auto c:chars) {
//        cout << c;
//    }
//    cout << endl;
        return 0;
    }
}
