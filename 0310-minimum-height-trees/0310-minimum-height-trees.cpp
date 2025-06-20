class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<vector<int>> graph(n);
        vector<int> degree(n, 0);
        for (auto& edge : edges) {
            degree[edge[0]]++;
            degree[edge[1]]++;
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int count = 0;
        bool final = false;
        vector<int> result;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
                count++;
            }
        }
        while (!q.empty()) {
            if (count == n) final = true;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();
                if (final) result.push_back(node);
                for (int neighbor : graph[node]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) {
                        q.push(neighbor);
                        count++;
                    }
                }                
            }
        }
        return result;
    }
};
/*
Roots of min tree height -> nodes in the center of the tree (1 or 2 nodes)
How to find the center? Start from leaves and trim them until the final round
Like Kahn's algorithm (topological order), utilize degree (not considering directions)
*/