class Solution {
private:
    int m;
    int n;
    const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<bool>> p_ocean(m, vector<bool>(n, false));
        vector<vector<bool>> a_ocean(m, vector<bool>(n, false));
        vector<vector<int>> ans;
        // dfs from margin cells
        for (int i = 0; i < m; i++) {
            dfs(heights, i, 0, p_ocean);
            dfs(heights, i, n - 1, a_ocean);
        }
        for (int j = 0; j < n; j++) {
            dfs(heights, 0, j, p_ocean);
            dfs(heights, m - 1, j, a_ocean);
        }
        // find the final ans
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (p_ocean[i][j] && a_ocean[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
private:
    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& visited) {
        if (visited[i][j]) {
            return;
        }
        visited[i][j] = true;
        for (auto [dx, dy] : directions) {
            int x = i + dx;
            int y = j + dy;
            if (x >= 0 && x < m && y >= 0 && y < n && heights[x][y] >= heights[i][j]) {
                dfs(heights, x, y, visited);
            }
        }
    }
};

/*
vector<vector<bool>> p
vector<vector<bool>> a
in the beginning, we can only know the desination of marginal cells
-> reverse the question, use DFS/BFS from marginal cells to other heigher cells to find the resource
*/