class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int total = 0, n = points.size(), edge = 0;
        vector<int> visited(n, false);
        vector<int> minDist(n, INT_MAX); // min dist from a node to any nodes in MST
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap; // weight, node
        minHeap.push({0, 0});
        while (edge < n) {
            auto [w, node] = minHeap.top();
            minHeap.pop();
            if (visited[node]) continue;
            visited[node] = true;
            total += w;
            edge++;
            for (int i = 0; i < n; i++) {
                if (visited[i]) continue;
                int dist = abs(points[node][0] - points[i][0]) + abs(points[node][1] - points[i][1]);
                if (dist < minDist[i]) {
                    minDist[i] = dist;
                    minHeap.push({dist, i});
                }
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

Note: don't need to record the weights in advance, calculate it when needed

Time Complexity: O(n^2 * log n)
Space Complexity: O(n)
*/