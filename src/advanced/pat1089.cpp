//
// Created by neild47 on 18-7-12.
//
#include <iostream>
#include <vector>
#include <algorithm>

/**
 *
 * 另一种解法，本题的数据量很小，完全可以不使用merge sort。
 * 思路是首先判断是否为插入排序，如果不是的话对每一个区间进行sort就可以。
 * 启发是数据量很小的时候可以使用stl来模拟一些复杂的操作。
#include <iostream>
#include <algorithm>
using namespace std;
int cmp(int a, int b) {
    return a < b;
}
int main() {
    int n;
    cin >> n;
    int *a = new int [n];
    int *b = new int [n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int i, j;
    for (i = 0; i < n - 1 && b[i] <= b[i + 1]; i++);
    for (j = i + 1; a[j] == b[j] && j < n; j++);
    if (j == n) {
        cout << "Insertion Sort" << endl;
        sort(a, a + i + 2, cmp);
    } else {
        cout << "Merge Sort" << endl;
        int k = 1;
        int flag = 1;
        while(flag) {
            flag = 0;
            for (i = 0; i < n; i++) {
                if (a[i] != b[i])
                    flag = 1;
            }
            k = k * 2;
            for (i = 0; i < n / k; i++)
                sort(a + i * k, a + (i + 1) * k, cmp);
            for (i = n / k * k; i < n; i++)
                sort(a + n / k * k, a + n, cmp);
        }
    }

    for (j = 0; j < n - 1; j++) {
        cout << a[j] << " ";
    }
    cout << a[n - 1];
    return 0;
}
 * **/

namespace pat1089 {
    using namespace std;

    void printArr(const vector<int> &);

    void merge(vector<int> &arr, int s1, int s2) {
        inplace_merge(arr.begin() + s1, arr.begin() + s2, arr.begin() + min(s2 + s2 - s1, (int) arr.size()));
    }

    void mergeSort(vector<int> &arr, int block) {
        int i = 0;
        while (i < arr.size()) {
            if (i + block >= arr.size()) break;
            merge(arr, i, i + block);
            i += 2 * block;
        }
    }

    void printArr(const vector<int> &arr) {
        for (int i = 0; i < arr.size(); i++) {
            if (i != 0) cout << " ";
            cout << arr[i];
        }
        cout << endl;
    }

    bool isInsertionSort(const vector<int> &init, const vector<int> &seq) {
        int i = is_sorted_until(seq.begin(), seq.end()) - seq.begin();
        for (; i < seq.size(); i++) {
            if (seq[i] != init[i]) return false;
        }
        return true;
    }

    void insertionSort(vector<int> &arr) {
        int iter = is_sorted_until(arr.begin(), arr.end()) - arr.begin();
        if (iter == arr.size()) return;
        while (iter - 1 >= 0) {
            if (arr[iter - 1] > arr[iter]) {
                swap(arr[iter - 1], arr[iter]);
                iter--;
            } else {
                break;
            }
        }
    }

    int nextStep(const vector<int> &arr) {
        for (int block = 2; block < arr.size(); block *= 2) {
            for (int i = 0; i < arr.size(); i += block) {
                if (!is_sorted(arr.begin() + i, arr.begin() + min(i + block, (int) arr.size()))) {
                    return block;
                }
            }
        }
    }

    int main() {
        int n, v;
        cin >> n;
        vector<int> init, seq;
        for (int i = 0; i < n; i++) {
            cin >> v;
            init.push_back(v);
        }
        for (int i = 0; i < n; i++) {
            cin >> v;
            seq.push_back(v);
        }
        if (isInsertionSort(init, seq)) {
            cout << "Insertion Sort" << endl;
            insertionSort(seq);
            printArr(seq);
        } else {
            cout << "Merge Sort" << endl;
            int step = nextStep(seq);
            mergeSort(seq, step / 2);
            printArr(seq);
        }
        return 0;
    }
}
