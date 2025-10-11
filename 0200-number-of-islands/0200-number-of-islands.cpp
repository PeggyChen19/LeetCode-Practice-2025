class UnionFind {
public:
    vector<int> parent; // turn 2-dimension vector to 1 by i*col_size+j
    vector<int> rank;
    int count;

    UnionFind(int size) {
        rank.resize(size, 0);
        for (int i = 0; i < size; i++) {
            parent.push_back(i); // the parent is itself in the beginning
        }
    }

    int Find(int n) {
        if (parent[n] != n) {
            parent[n] = Find(parent[n]); // recursive until the root
        }
        return parent[n];
    }

    void Union(int a, int b) {
        int root_a = Find(a);
        int root_b = Find(b);
        if (root_a == root_b) { // in the same set already
            return;
        }
        if (rank[root_a] > rank[root_b]) {
            parent[root_b] = root_a;
        } else if (rank[root_b] > rank[root_a]) {
            parent[root_a] = root_b;
        } else {
            parent[root_a] = root_b;
            rank[root_b]++;
        }
        count--;
    }

};

class Solution {
private:
    const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        UnionFind uf(m * n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    uf.count++;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    // grid[i][j] = '0';
                    for (auto [dx, dy] : directions) {
                        int x = i + dx;
                        int y = j + dy;
                        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1') {
                            uf.Union((i * n + j), (x * n + y));
                        }
                    }
                }
            }
        }
        return uf.count;
    }
};