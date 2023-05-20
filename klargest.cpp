#include <queue>
#include <vector>

int kth_largest(std::vector<int> values, int k) {
    std::priority_queue<int> maxHeap;
    for (int i = 0; i < values.size(); ++i) {
        maxHeap.push(values[i]);
    }
    for (int i = 1; i < k; ++i) {
        maxHeap.pop();
    }
    return maxHeap.top();
}