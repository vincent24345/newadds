#include <vector>
#include <queue>

int kth_largest(std::vector<int> values, int k) {
    std::priority_queue<int> pq(values.begin(), values.end());
    for(int i = 0; i < k - 1; ++i) {
        pq.pop();
    }
    return pq.top();
}
