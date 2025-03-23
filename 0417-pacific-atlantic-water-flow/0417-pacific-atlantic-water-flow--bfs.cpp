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
        queue<pair<int, int>> p_q;
        queue<pair<int, int>> a_q;
        vector<vector<int>> ans;
        // dfs from margin cells
        for (int i = 0; i < m; i++) {
            p_q.push({i, 0});
            a_q.push({i, n - 1});
        }
        for (int j = 0; j < n; j++) {
            p_q.push({0, j});
            a_q.push({m - 1, j});
        }
        bfs(heights, p_q, p_ocean);
        bfs(heights, a_q, a_ocean);
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
    void bfs(vector<vector<int>>& heights, queue<pair<int, int>>& q, vector<vector<bool>>& visited) {
        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if (visited[i][j]) {
                continue;
            }
            visited[i][j] = true;
            for (auto [dx, dy] : directions) {
                int x = i + dx;
                int y = j + dy;
                if (x >= 0 && x < m && y >= 0 && y < n && heights[x][y] >= heights[i][j]) {
                    q.push({x, y});
                }
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