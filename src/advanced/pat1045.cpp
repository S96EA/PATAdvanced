//
// Created by neild47 on 18-6-12.
//
#include <iostream>
#include <vector>

/**
 *


#include <vector>
using namespace std;
int book[201], a[10001], dp[10001];
int main() {
    int n, m, x, l, num = 0, maxn = 0;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        scanf("%d", &x);
        book[x] = i;
    }
    scanf("%d", &l);

    // 压缩数组，a存储的是原数组对应颜色在习惯颜色中的下标
    for(int i = 0; i < l; i++) {
        scanf("%d", &x);
        if(book[x] >= 1)
            a[num++] = book[x];
    }

    for(int i = 0; i < num; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
            // 通过a数组的意义，可以知道当a[i] >= a[j]时符合条件
            if(a[i] >= a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        maxn = max(dp[i], maxn);
    }
    printf("%d", maxn);
    return 0;
}



 *
 * **/

using namespace std;

namespace pat1045 {
    int favoriteColors[210];
    int stripe[10010];
    int lenF, lenS;
    int maxarr[10010][210];

    // 这个算法还是有优化的地方，首先可以将递归版本的lcs改变为迭代版本，其次可以将不属于喜欢颜色的颜色去掉进一步压缩stripe数组
    // 这个版本的算法已经可以全部AC了
    int lcs(int currF, int currS) {
        if (currF < 0 || currS < 0) {
            return 0;
        }
        if (maxarr[currS][currF] != 0) return maxarr[currS][currF];

        if (stripe[currS] == favoriteColors[currF]) {
            maxarr[currS][currF] = max(lcs(currF - 1, currS - 1) + 1, lcs(currF, currS - 1) + 1);
        } else {
            maxarr[currS][currF] = max(lcs(currF - 1, currS), lcs(currF, currS - 1));
        }
        return maxarr[currS][currF];
    }

    int main() {
        int n;
        cin >> n;
        scanf("%d", &lenF);
        for (int i = 0; i < lenF; ++i) {
            scanf("%d", &favoriteColors[i]);
        }
        scanf("%d", &lenS);
        for (int i = 0; i < lenS; ++i) {
            scanf("%d", &stripe[i]);
        }

        cout << lcs(lenF - 1, lenS - 1) << endl;
        return 0;
    }
}
