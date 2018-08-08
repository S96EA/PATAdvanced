//
// Created by neild47 on 18-6-11.
//
/**
 *
 *
 * 尽量使用scanf、printf代替cin和cout，会获得较高的效率。
 *
 *
 * **/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

namespace pat1039 {
    const int hashsize = 26 * 26 * 26 * 10;
    const int p4 = 26 * 26 * 10;
    const int p3 = 26 * 10;
    const int p2 = 10;

    int nameToHash(char *s) {
        return (s[0] - 'A') * p4 + (s[1] - 'A') * p3 + (s[2] - 'A') * p2 + (s[3] - '0');
    }

    vector<int> nameHash[hashsize];

    int main() {
        int n, k;
        cin >> n >> k;
        char name[5] = {0};
        for (int i = 0; i < k; i++) {
            int c, ns;
            scanf("%d%d", &c, &ns);
            for (int j = 0; j < ns; j++) {
                scanf("%s", name);
                nameHash[nameToHash(name)].push_back(c);
            }
        }

        for (int i = 0; i < n; i++) {
            scanf("%s", name);
            auto &v = nameHash[nameToHash(name)];
            printf("%s %d", name, (int) v.size());
            sort(v.begin(), v.end());
            for (auto c:v) {
                printf(" %d", c);
            }
            printf("\n");
        }
        return 0;
    }

}
