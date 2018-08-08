#include <iostream>
#include <string>
#include <stack>

using namespace std;

namespace pat1001 {
    int main() {
        int a, b;
        cin >> a >> b;
        string s = to_string(a + b);
        stack<char> chars;
        int length = s.size();
        for (int i = 0; i < length; i++) {
            chars.push(s[length - i - 1]);
            if ((i + 1) % 3 == 0 && (length - i - 1) != 0) {
                if (s[0] == '-' && (length - i - 1) == 1) {
                } else {
                    chars.push(',');
                }
            }
        }
        while (!chars.empty()) {
            cout << chars.top();
            chars.pop();
        }
        return 0;
    }
}