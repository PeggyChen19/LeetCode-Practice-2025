class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        using T = pair<int, vector<int>>;
        vector<T> distance;
        vector<vector<int>> results;
        for (int i = 0; i < points.size(); i++) {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            distance.push_back({dist, points[i]});
        }
        priority_queue<T, vector<T>, greater<T>> minHeap(distance.begin(), distance.end());
        for (int i = 0; i < k; i++) { // do it k times
            results.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return results;
    }
};
/*
For comparing distance, we can use points[0]^2 + points[1]^2
(Don't need square root because it won't affect the order of their relative magnitudes)
Top K small values -> priority queue / quick select
Priority Queue - Min Heap
Put the whole vector into heap: O(n)
Retrieve the kth element: O(klogn)
*/