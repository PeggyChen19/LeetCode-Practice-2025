class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int total = 0, n = points.size(), count = 0;
        vector<int> visited(n, false);
        vector<int> minDist(n, INT_MAX); // min dist from a node to any nodes in MST
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap; // weight, node
        minDist[0] = 0;
        minHeap.push({0, 0});
        while (count < n) {
            auto [w, node] = minHeap.top();
            minHeap.pop();
            if (visited[node]) continue;
            visited[node] = true;
            total += w;
            count++;
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

Time Complexity: O(n^2 logn)
但是實際上 push 跟 pop 次數會分別大約做 n 次，檢查鄰居的成本是 n^2 -> 平均會接近 O(n^2)
Space Complexity: O(n)
*/