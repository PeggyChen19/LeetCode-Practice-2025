class Solution {
private:
    int find(int a, vector<int>& parent) {
        if (a != parent[a]) {
            parent[a] = find(parent[a], parent);
        }
        return parent[a];
    }
    bool unite(int a, int b, vector<int>& parent, vector<int>& rank) {
        int rootA = find(a, parent), rootB = find(b, parent);
        if (rootA == rootB) return false; // already in the same set
        if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        } else if (rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
        } else {
            parent[rootA] = rootB;
            rank[rootB]++;
        }
        return true;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int v = points.size();
        vector<int> parent(v);
        vector<int> rank(v, 1);
        for (int i = 0; i < v; i++) {
            parent[i] = i;
        }
        vector<vector<int>> edges; // weight, node(smaller ind), node(bigger ind), 
        for (int i = 0; i < v; i++) {
            for (int j = i + 1; j < v; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            }
        }
        sort(edges.begin(), edges.end());
        int count = 0, total = 0;
        for (auto& edge : edges) {
            int w = edge[0], n1 = edge[1], n2 = edge[2];
            if (unite(n1, n2, parent, rank)) {
                count++;
                total += w;
            }
            if (count == v - 1) break;
        }
        return total;
    }
};
/*
Kruskal's algo for MST
Set up union find
Sort the edges
For each edge (from small to big)
    united two sets
    update MST
    break when number of edges in MST == n-1
*/