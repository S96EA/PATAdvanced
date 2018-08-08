//
// Created by neild47 on 18-7-23.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
namespace pat1105 {

    int matrix[10010][10010];
    int m, n;

    void fill(const vector<int> &v) {
        int posX = 1, posY = 1;
        int vX = 0, vY = 1;
        for (auto item:v) {
            matrix[posX][posY] = item;
            if (!vX && vY == 1 && (posY + vY > n || matrix[posX][posY + vY])) {
//            cout << "=============1" << endl;
                vY = 0;
                vX = 1;
            } else if (vX == 1 && !vY && (posX + vX > m || matrix[posX + vX][posY])) {
//            cout << "=============2" << endl;
                vX = 0;
                vY = -1;
            } else if (!vX && vY == -1 && (posY + vY < 1 || matrix[posX][posY + vY])) {
//            cout << "=============3" << endl;
                vX = -1;
                vY = 0;
            } else if (vX == -1 && !vY && (posX + vX < 1 || matrix[posX + vX][posY])) {
//            cout << "=============4" << endl;
                vX = 0;
                vY = 1;
            }
            posX += vX;
            posY += vY;
        }
    }

    void printMatrix() {
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (j != 1) printf(" ");
                printf("%d", matrix[i][j]);
            }
            printf("\n");
        }
    }

    int main() {
        int N, v;
        cin >> N;
        m = N, n = 1;
        for (int i = 2; i <= N; i++) {
            if (N % i == 0) {
                int nn = i;
                int nm = N / i;
                if (nn <= nm && m - n > nm - nn) {
                    m = nm;
                    n = nn;
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < N; i++) {
            scanf("%d", &v);
            ans.push_back(v);
        }


        sort(ans.begin(), ans.end(), std::greater<int>());
        fill(ans);
        printMatrix();
        return 0;
    }
}
