//
// Created by neild47 on 18-6-10.
//

/**
 *
 *
用回溯做的话最后一个用例过不去，其实只需要写一个cmp函数然后排序就好了
原来想的是如果两个segemnt的长度不相同就不能比较大小，但是使用a+b<b+a这个比较策略就可以
正确性可以证明：最小的组合中

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool cmp0(string a, string b) {
    return a + b < b + a;
}
string str[10010];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        cin >> str[i];
    sort(str, str + n, cmp0);
    string s;
    for(int i = 0; i < n; i++)
        s += str[i];
    while(s.length() != 0 && s[0] == '0')
        s.erase(s.begin());
    if(s.length() == 0) cout << 0;
    cout << s;
    return 0;
}
 *
 * **/

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <string>

using namespace std;

namespace std {


    vector<string> ans, highest;
    vector<string> numbers;
    int n;
    bool vis[10010];

    int cmp(vector<string> &v1, vector<string> &v2) {
        auto iter1 = v1.begin(), iter2 = v2.begin();
        int i1 = 0, i2 = 0;
        while (iter1 != v1.end() && iter2 != v2.end()) {
            for (; i1 < iter1->size() && i2 < iter2->size(); i1++, i2++) {
                if ((*iter1)[i1] != (*iter2)[i2]) return (*iter1)[i1] < (*iter2)[i2] ? -1 : 1;
            }
            if (i1 == iter1->size()) {
                i1 = 0;
                iter1++;
            }
            if (i2 == iter2->size()) {
                i2 = 0;
                iter2++;
            }
        }
        if (iter1 == v1.end() && iter2 == v2.end()) return 2;
        return 0;
    }

    void dfs(int curr) {
        int cp = cmp(ans, highest);
        if (cp == 1 || cp == 2) return;
        if (curr == n) {
            if (cmp(ans, highest) == -1) {
                highest = ans;
            }
            return;
        }

        set<string> sets;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && sets.count(numbers[i]) == 0) {
                vis[i] = true;
                ans.push_back(numbers[i]);
                sets.insert(numbers[i]);
                dfs(curr + 1);
                ans.pop_back();
                vis[i] = false;
            }
        }
    }

    int main() {
        cin >> n;
        string s;
        for (int i = 0; i < n; i++) {
            cin >> s;
            numbers.push_back(s);
        }
        sort(numbers.begin(), numbers.end());
        highest = numbers;
        dfs(0);
        string ss;
        for (int i = 0; i < n; i++) {
            ss += highest[i];
        }
        while (!ss.empty() && ss[0] == '0') { ss.erase(ss.begin()); }
        if (ss.empty()) cout << 0 << endl;
        else cout << ss << endl;
        return 0;
    }
}
