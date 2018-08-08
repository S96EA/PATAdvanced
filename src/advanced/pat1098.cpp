//
// Created by neild47 on 18-7-18.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
namespace pat1098 {
    vector<int> rowSeq, midSeq;

    bool isInsertion() {
        int i = is_sorted_until(midSeq.begin(), midSeq.end()) - midSeq.begin();
        for (; i < rowSeq.size(); i++) {
            if (rowSeq[i] != midSeq[i]) return false;
        }
        return true;
    }


    void insertionSort() {
        int i = is_sorted_until(midSeq.begin(), midSeq.end()) - midSeq.begin();
        int num = midSeq[i];
        i--;
        for (; i >= 0 && midSeq[i] > num; i--) {
            midSeq[i + 1] = midSeq[i];
        }
        i++;
        midSeq[i] = num;
    }

    void heapSort() {
        make_heap(rowSeq.begin(), rowSeq.end());
        auto endIter = rowSeq.end();
        while (rowSeq != midSeq) {
            pop_heap(rowSeq.begin(), endIter);
            endIter--;
        }
        pop_heap(rowSeq.begin(), endIter);

        for (int i = 0; i < rowSeq.size(); i++) {
            if (i != 0) cout << " ";
            cout << rowSeq[i];
        }
    }

    int main() {
        int n, v;
        cin >> n;
        for (int i = 0; i < n; i++) {
            scanf("%d", &v);
            rowSeq.push_back(v);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &v);
            midSeq.push_back(v);
        }

        if (isInsertion()) {
            cout << "Insertion Sort" << endl;

            insertionSort();
            for (int i = 0; i < midSeq.size(); i++) {
                if (i != 0) cout << " ";
                cout << midSeq[i];
            }
        } else {
            cout << "Heap Sort" << endl;
            heapSort();
        }
        return 0;
    }
}
