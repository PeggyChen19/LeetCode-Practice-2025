class Solution {
public:
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> results(n, vector<int>(m, INT_MAX));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    results[i][j] = 0;
                } else {
                    bfs(mat, i, j, results);
                }
            }
        }
        return results;
    }
private:
    void bfs(vector<vector<int>>& mat, int i, int j, vector<vector<int>>& results) {
        int layer = 1;
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
            int size = q.size();
            if (results[i][j] <= layer) { // have found nearest 0
                return;
            }
            for (int s = 0; s < size; s++) { // same layer
                auto [a, b] = q.front();
                q.pop();
                for (auto& [dx, dy] : directions) {
                    int x = a + dx;
                    int y = b + dy;
                    if (x < 0 || x >= mat.size() || y < 0 || y >= mat[0].size()) {
                        continue;
                    }
                    if (mat[x][y] == 0) {
                        results[i][j] = min(results[i][j], layer);
                        return;
                    } else { // 1
                        if (results[x][y] != INT_MAX) { // calculated
                            results[i][j] = min(results[i][j], layer + results[x][y]);
                        } else {
                            q.push({x, y});
                        }
                    }
                }
            }
            layer++;
        }
    }
};
/*
Find the nearest "0" -> BFS
Can we improve it?
Refer to the result of other 1 points?
If we reach a 1 point and it has have the answer -> use the answer + the distance of two 1's
*/