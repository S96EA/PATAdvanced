//
// Created by neild47 on 18-6-7.
//
#include <iostream>

using namespace std;

/*
 *
 * 大神的做法：
 *
using namespace std;
int main() {
    char c[14] = {"0123456789ABC"};
    printf("#");
    for(int i = 0; i < 3; i++) {
        int num;
        scanf("%d", &num);
        printf("%c%c", c[num/13], c[num%13]);
    }
    return 0;
}
 *
 * */

namespace pat1027 {

    string mm[] = {"A", "B", "C"};

    string decTo13(int a) {
        if (a == 0) {
            return "00";
        } else {
            string s;
            //题目都说了是最多168的，所以这里的while完全不需要。脑子抽了
            while (a != 0) {
                int c = a % 13;
                if (c < 10) {
                    s = to_string(c) + s;
                } else {
                    c -= 10;
                    s = mm[c] + s;
                }
                a /= 13;
            }
            if (s.size() == 1) s = "0" + s;
            return s;
        }
    }


    int main() {
        int r, g, b;
        cin >> r >> g >> b;
        cout << "#" << decTo13(r) << decTo13(g) << decTo13(b) << endl;
        return 0;
    }
}
