class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int total = 0, n = points.size();
        vector<int> visited(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap; // weight, node
        minHeap.push({0, 0});
        while (!minHeap.empty()) {
            auto [w, node] = minHeap.top();
            minHeap.pop();
            if (visited[node]) continue;
            visited[node] = true;
            total += w;
            for (int i = 0; i < n; i++) {
                if (visited[i]) continue;
                int dist = abs(points[node][0] - points[i][0]) + abs(points[node][1] - points[i][1]);
                minHeap.push({dist, i});
            }
        }
        return total;
    }
};
/*
Minimum Spanning Tree
Every two points can build an edge
n points, n*(n-1)/2 edges
Dense Graph -> Prim's algorithm

Build visited vector
Build min heap
push the first point into minHeap
while !minHeap.empty()
    minHeap.top
    check if top node is visited or not
    update MST
    for all neighbors
        push into minHeap if not visited

Note: don't need to record the weights in advance, calculate it when needed

Time Complexity: O(n^2 * log n)
Space Complexity: O(n)
*/