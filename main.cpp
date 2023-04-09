#include <algorithm>
#include <iostream>
#include <vector>

#include "Sort.h"
#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

using namespace std;

int main() {
    //create a random list of unordered numbers
    int arr[] = {3, 1, 8, 2, 9, 5, 4, 7, 6, 0, 10};
    vector<int> list(arr, arr + sizeof(arr) / sizeof(int));

    //create sort objects
    Sort* bubbleSort = new BubbleSort;
    Sort* quickSort = new QuickSort;

    //sort the list
    vector<int> ans = bubbleSort->sort(list);
    vector<int> ans2 = quickSort->sort(list);

    //print the sorted list
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < ans2.size(); i++) {
        cout << ans2[i] << " ";
    }
    cout << endl;

    //create search object
    RecursiveBinarySearch* binarySearch = new RecursiveBinarySearch;

    //search for a number
    int target = 5;
    int index = binarySearch->search(ans, target);

    //print the index of the number
    cout << "The index of " << target << " is " << index << endl;

    return 0;
}
