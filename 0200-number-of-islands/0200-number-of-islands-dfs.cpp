class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    result++;
                }
            }
        }
        return result;
    }
private:
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    void dfs(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';
        for (auto& [dx, dy] : directions) {
            int x = i + dx;
            int y = j + dy;
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == '1') {
                dfs(grid, x, y);
            }
        }
    }
};
/*
DFS / BFS
After visiting -> set to 0 (water)
go through the matrix, explore every island, return the count
*/