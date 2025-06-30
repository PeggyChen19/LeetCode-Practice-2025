class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int m = image.size(), n = image[0].size();
        int original = image[sr][sc];
        if (original == color) return image; // no need to change
        queue<pair<int, int>> q;
        q.push({sr, sc});
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto [dx, dy] : directions) {
                int newX = x + dx;
                int newY = y + dy;
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && image[newX][newY] == original) {
                    image[newX][newY] = color;
                    q.push({newX, newY});
                }
            }
        }
        return image;
    }
};
/*
Record the original color
Do BFS / DFS to fill the neighbors with original color
*/