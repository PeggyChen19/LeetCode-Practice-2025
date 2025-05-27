class Solution {
private:
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> results(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    results[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (auto& [dx, dy] : directions) {
                int x = i + dx;
                int y = j + dy;
                if (x < 0 || x >= n || y < 0 || y >= m) { // invalid
                    continue;
                }
                if (results[x][y] > results[i][j] + 1) {
                    results[x][y] = results[i][j] + 1; // update smaller distance
                    q.push({x, y}); // push into queue -> update others later
                }
            }
        }
        return results;
    }
};
/*
find the nearest 0 -> BFS
start from all 0 and keep updating their neighbors to smaller distance
set distance = 0 for all 0
push all 0 into queue
for all neighbors
    if shorter -> update distance and push into queue
*/