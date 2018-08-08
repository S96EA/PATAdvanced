#include <iostream>
#include <stack>

using namespace std;

namespace pat1057 {

#define MAXN 100010
#define lowbit(x) ((x)&(-(x)))

    int c[MAXN + 10];

    void add(int idx, int value) {
        while (idx <= MAXN) {
            c[idx] += value;
            idx += lowbit(idx);
        }
    }

    int getSum(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += c[idx];
            idx -= lowbit(idx);
        }
        return sum;
    }

    int peekK(int k) {
        int lo = 1, hi = MAXN;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (getSum(mid) >= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }

    int main() {
        int n, v;
        char cmd[15];
        stack<int> numStack;
        cin >> n;
        for (int i = 0; i < n; i++) {
            scanf("%s", cmd);
            if (cmd[1] == 'o') {//Pop
                if (numStack.empty()) printf("Invalid\n");
                else {
                    printf("%d\n", numStack.top());
                    add(numStack.top(), -1);
                    numStack.pop();
                }
            } else if (cmd[1] == 'u') {//Push
                scanf("%d", &v);
                add(v, 1);
                numStack.push(v);
            } else if (cmd[1] == 'e') {
                if (numStack.empty()) printf("Invalid\n");
                else printf("%d\n", peekK((numStack.size() + 1) / 2));
            }
        }
    }
}
