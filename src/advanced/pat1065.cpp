#include <iostream>

using namespace std;

namespace pat1066 {

    bool cmp(const long long &v1, const long long &v2, const long long &v3) {
        if (v1 > 0 && v2 > 0 && v1 + v2 < 0) return true;
        if (v1 < 0 && v2 < 0 && v1 + v2 > 0) return false;

        return v1 + v2 > v3;
    }

    int main() {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            long long v1, v2, v3;
            cin >> v1 >> v2 >> v3;
            bool isGreater = cmp(v1, v2, v3);
            printf("Case #%d: ", i + 1);
            cout << (isGreater ? "true" : "false") << endl;
        }
        return 0;
    }
}
