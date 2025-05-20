class Solution {
private:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0 , 1}, {0, -1}};
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        // handle edges O -> B
        for (int i = 0; i < n; i++) {
            dfs(board, i, 0);
            dfs(board, i, m - 1);
        }
        for (int j = 0; j < m; j++) {
            dfs(board, 0, j);
            dfs(board, n - 1, j);
        }
        // O -> X
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
        // E -> O
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'E') {
                    board[i][j] = 'O';
                }
            }
        }
    }
private:
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] != 'O') {
            return;
        }
        board[i][j] = 'E';
        for (auto& [dx, dy] : directions) {
            int x = i + dx;
            int y = j + dy;
            if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size()) {
                dfs(board, x, y);
            }
        }
    }
};
/*
If "O" region is surrounded by "X" (not edges) -> become "X"

Brute-Force:
When encounting an "O"
if there are at least one edge -> ignore
if there are at least one "O" connected -> DFS/BFS to find the region
else -> mark it as "X"
--> Complicated

Improvement:
1. Mark the "O" region start from edge as "B"
2. Mark all remainign "O" as "X"
3. Turn all "B" back to "O"

Insight:
Graph 當發現暴力解太複雜，換個角度切入（換個 target value of elements / 從邊角開始 / 顛倒方向）
*/