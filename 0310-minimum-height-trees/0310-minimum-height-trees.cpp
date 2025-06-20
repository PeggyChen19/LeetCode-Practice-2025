class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<vector<int>> graph(n);
        vector<int> degree(n, 0);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            degree[u]++;
            degree[v]++;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) q.push(i);
        }
        while (n > 2) {
            int size = q.size();
            n -= size;
            for (int i = 0; i < size; i++) {
                int node = q.front(); q.pop();
                for (int neighbor : graph[node]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }                
            }
        }
        vector<int> result;
        while (!q.empty()) {
            int center = q.front(); q.pop();
            result.push_back(center);
        }
        return result;
    }
};
/*
Roots of min tree height -> nodes in the center of the tree (1 or 2 nodes)
How to find the center? Start from leaves and trim them until the final round
Like Kahn's algorithm (topological order), utilize degree (not considering directions)
*/