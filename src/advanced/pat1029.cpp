#include <climits>
#include <queue>
#include <iostream>

using namespace std;
namespace pat1029 {
    int main() {
        queue<int> a, b;
        long long tnum;
        int n, m, num, cnt = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &tnum);
            num = min((long long) INT_MAX, tnum);
            a.push(num);
        }
        a.push(INT_MAX);
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%lld", &tnum);
            int num = min((long long) INT_MAX, tnum);
            b.push(num);
            if (cnt == (n + m - 1) / 2) {
                printf("%d", min(a.front(), b.front()));
                return 0;
            }
            if (a.front() < b.front())
                a.pop();
            else
                b.pop();
            cnt++;
        }
        b.push(INT_MAX);
        for (; cnt < (n + m - 1) / 2; cnt++) {
            if (a.front() < b.front())
                a.pop();
            else
                b.pop();
        }
        printf("%d", min(a.front(), b.front()));
        return 0;
    }
}