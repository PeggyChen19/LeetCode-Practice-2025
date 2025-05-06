class Solution {
private:
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int global_max = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    int size = 0;
                    DFS(grid, i, j, size);
                    global_max = max(global_max, size);
                }
            }
        }
        return global_max;
    }
private:
    void DFS(vector<vector<int>>& grid, int i, int j, int& size) {
        grid[i][j] = 0; // visited
        size++;
        for (auto [dx, dy] : directions) {
            int x = i + dx;
            int y = j + dy;
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y]) {
                DFS(grid, x, y, size);
            }
        }
    }
};
/*
use BFS / DFS to tranverse all island
visited -> change to zero
create var global_max to record the max island
*/