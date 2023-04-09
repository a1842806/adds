#include <vector>
#include "RecursiveBinarySearch.h"

int binarySearch(int left, int right, std::vector<int> list, int target) {
    if (left > right) return -1;
    int mid = (left + right) >> 1;
    if (list[mid] == target) return mid;
    if (list[mid] > target) return binarySearch(left, mid - 1, list, target);
    return binarySearch(mid + 1, right, list, target);
}

int RecursiveBinarySearch::search(std::vector<int> list, int target) {
    return binarySearch(0, list.size() - 1, list, target);
}