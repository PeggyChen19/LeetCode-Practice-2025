class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        using T = pair<int, vector<int>>; // distance, point vector
        priority_queue<T> maxHeap;
        for (auto& point : points) {
            int dist = point[0] * point[0] + point[1] * point[1];
            maxHeap.push({dist, point});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        vector<vector<int>> results;
        while (!maxHeap.empty()) {
            results.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return results;
    }
};
/*
Priority Queue - Max Heap
Push the element one by one 
    when size == k
        pop
O(nlogk)
*/