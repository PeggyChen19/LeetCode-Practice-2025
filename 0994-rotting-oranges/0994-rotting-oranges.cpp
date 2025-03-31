class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int m = grid.size(), n = grid[0].size();
        int fresh_count = 0, ans = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fresh_count++;
                } else if (grid[i][j] == 2) { // rotten -> starting point
                    q.push({i, j});
                    ans = -1; // we have to handle rotten ones previously
                }
            }
        }
        while (!q.empty()) {
            int layer_size = q.size();
            for (int k = 0; k < layer_size; k++) {
                auto [i, j] = q.front();
                q.pop();
                for (auto [dx, dy] : directions) {
                    int x = i + dx;
                    int y = j + dy;
                    if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) { // fresh
                        grid[x][y] = 2;
                        fresh_count--;
                        q.push({x, y});
                    }
                }
            }
            ans++;
        }
        return (fresh_count > 0)? -1 : ans;
    }
};
/*
010 010 020
111 121 222
021 022 022

BFS -> queue
for all rotten
    push into queue
while q is not empty
    for all cells in this layer
        pop top
        for all fresh neighbors of top
            change it to rotten
            add to queue
    ans++
check if there has fresh oranges
*/