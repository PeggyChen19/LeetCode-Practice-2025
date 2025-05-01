class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int kth;
    KthLargest(int k, vector<int>& nums): kth(k) {
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > kth) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);

min heap, push everything and pop item when heap size > k
when heap size == k, the top is the k largest element

Time Complexity:
init: O(nlogk)
add: (logk)

 */