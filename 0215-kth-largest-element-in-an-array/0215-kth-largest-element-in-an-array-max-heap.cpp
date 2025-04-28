class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> max_heap(nums.begin(), nums.end());
        for (int i = 1; i <= k-1; i++) {
            max_heap.pop();
        }
        return max_heap.top();
    }
};
/*
Max heap:
heapify the whole vector
for 1~k-1
    pop
Time Complexity
O(n + klogn)
Space Complexity
O(n)
*/