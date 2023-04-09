#include <algorithm>
#include <vector>
#include <iostream>
#include "Sort.h"
#include "QuickSort.h"

void smallSort(int left, int right, std::vector<int> &list) {
    if (right <= left) return;
    if (right - left == 1) {
        if (list[left] > list[right]) std::swap(list[left], list[right]);
        return;
    }
    std::swap(list[left + 2], list[right]);
    int i = left;
    int j = right - 1;
    while (i < j) {
        while (list[i] < list[right]) i++;
        while (list[j] > list[right]) j--;
        if (i < j) std::swap(list[i++], list[j--]);
    }
    std::swap(list[i], list[right]);
    smallSort(left, i - 1, list);
    smallSort(i + 1, right, list);
}

std::vector<int> QuickSort::sort(std::vector<int> list) {
    smallSort(0, list .size() - 1, list);
    return list;
}