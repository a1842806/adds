#include <algorithm>
#include <iostream>
#include <vector>

#include "Sort.h"
#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

using namespace std;

int main() {
    int x;
    vector<int> list;
    while (cin >> x) {
        list.push_back(x);
    }
    Sort *sorter = new QuickSort();
    list = sorter->sort(list);

    RecursiveBinarySearch *searcher = new RecursiveBinarySearch();
    int index = searcher->search(list, 1);

    cout << (index == -1 ? "False" : "True");
    for (int i = 0; i < list.size(); i++) {
        cout << " " << list[i];
    }
    return 0;
}
