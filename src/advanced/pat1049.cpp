//
// Created by neild47 on 18-6-13.
//

#include <iostream>

using namespace std;
namespace pat1049 {
    int main() {
        long n;
        cin >> n;
        long iter = 10;
        int i = 0;
        long ss = 0;
        while (n >= iter / 10) {
            ss += (n / iter) * (iter / 10);
            ss += min(max((n % iter - max((iter / 10 - 1), 0L)), 0L), iter / 10);
            iter *= 10;
            i++;
        }

        cout << ss << endl;

        return 0;
    }
}
