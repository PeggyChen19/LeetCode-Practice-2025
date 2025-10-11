class Solution {
private:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid);
                    count++;
                }
            }
        }
        return count;
    }
private:
    void dfs(int i, int j, vector<vector<char>>& grid) {
        grid[i][j] = '0'; // mark as visited
        for (auto [dx, dy] : directions) {
            int x = i + dx;
            int y = j + dy;
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == '1') {
                dfs(x, y, grid);
            }
        }
    }
};