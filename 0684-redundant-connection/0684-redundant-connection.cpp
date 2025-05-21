class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1, 0);
        vector<int> rank(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (unionSets(edges[i][0], edges[i][1], parent, rank)) {
                return edges[i];
            }
        }
        return {0, 0};
    }
private:
    int find(int a, vector<int>& parent) {
        if (parent[a] == 0) { // root
            return a;
        }
        parent[a] = find(parent[a], parent);
        return parent[a];
    }
    bool unionSets(int a, int b, vector<int>& parent, vector<int>& rank) {
        int rootA = find(a, parent);
        int rootB = find(b, parent);
        if (rootA == rootB) {
            return true;
        }
        if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        } else if (rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
        } else {
            parent[rootA] = rootB;
            rank[rootB]++;
        }
        return false;
    }
};
/*
Goal: remove cycle by removing one edge (multiple answers -> remove the last one in input)
Connected Components (detect & maintain) -> Union-Find (Disjoint Set)
Go through the edges one by one, check if the two nodes are in the same set or not
Yes -> redundant edge
No -> Union two sets
*/