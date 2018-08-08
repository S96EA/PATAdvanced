//
// Created by neild47 on 18-8-4.
//

#include <iostream>
#include <string>

using namespace std;
namespace pat1132 {
    int main() {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            unsigned long long a = atoll(s.data());
            unsigned long long a1 = atoll(s.substr(s.size() / 2).data());
            unsigned long long a2 = atoll(s.substr(0, s.size() / 2).data());
            if (a1 * a2 == 0) {
                printf("No\n");
            } else {
                printf(a % (a1 * a2) == 0 ? "Yes\n" : "No\n");
            }
        }
        return 0;
    }
}
