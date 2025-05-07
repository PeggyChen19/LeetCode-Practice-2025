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
                    global_max = max(global_max, BFS(grid, i, j));
                }
            }
        }
        return global_max;
    }
private:
    int BFS(vector<vector<int>>& grid, int i, int j) {
        int size = 0;
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 0;
        size++;
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (auto [dx, dy] : directions) {
                int x = i + dx;
                int y = j + dy; 
                if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y]) {
                    q.push({x, y});
                    grid[x][y] = 0;
                    size++;
                }
            }
        }
        return size;
    }
};
/*
use BFS / DFS to tranverse all island
visited -> change to zero
create var global_max to record the max island
*/