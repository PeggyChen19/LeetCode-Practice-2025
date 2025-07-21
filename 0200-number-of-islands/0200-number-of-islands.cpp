class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                   bfs(grid, i, j);
                   result++;
                }
            }
        }
        return result;
    }
private:
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    void bfs(vector<vector<char>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '0'; 
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto& [dx, dy] : directions) {
                int a = x + dx;
                int b = y + dy;
                if (a >= 0 && a < grid.size() && b >= 0 && b < grid[0].size() && grid[a][b] == '1') {
                    q.push({a, b});
                    grid[a][b] = '0';
                }
            }
        }
    }
};
/*
DFS / BFS
After visiting -> set to 0 (water)
go through the matrix, explore every island, return the count
*/