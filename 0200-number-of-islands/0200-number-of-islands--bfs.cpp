class Solution {
private:
    const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') { // starting point of land
                    bfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }

private:
    void bfs(vector<vector<char>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '0';
        while (!q.empty()) {
            i = q.front().first;
            j = q.front().second;    
            q.pop();
            for (auto [dx, dy] : directions) {
                int x = i + dx;
                int y = j + dy;
                if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == '1') {
                    q.push({x, y});
                    grid[x][y] = '0';
                }
            }
        }
    }
};

/*
loop the whole grid
    find the starting point land
    expand from 4 directions and marked it as "0" (visited) until reach water (DFS)
T: O(m*n)
*/