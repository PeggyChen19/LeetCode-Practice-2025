class Solution {
private:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = -1;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) { // rotten -> starting point
                    q.push({i, j});
                }
            }
        }
        q.push({-1, -1}); // separator
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if (i == -1 && j == -1) { // separator
                if (!q.empty()) { // not the last one
                    q.push({-1, -1});
                }
                ans++;
                continue;
            }
            for (auto [dx, dy] : directions) {
                int x = i + dx;
                int y = j + dy;
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) { // fresh
                    grid[x][y] = 2;
                    q.push({x, y});
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return ans;
    }
};
/*
010 010 020
111 121 222
021 022 022
BFS
use a queue (everything in the queue will be rotten)

queue bfs
for all rotten
    push into queue
add a separator
while q is not empty
    pop top
    for all fresh neighbors of top
        change it to rotten
        add to queue
    if encounter separator -> minutes++
check if there has fresh oranges
*/