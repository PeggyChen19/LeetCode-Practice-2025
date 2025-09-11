class Solution {
public:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                auto [live, dead] = checkNeighbors(board, i, j);
                if (board[i][j] == 1 && (live < 2 || live > 3)) {
                    board[i][j] = 2; // rule 1, 3
                } else if (board[i][j] == 0 && live == 3) { // rule 4
                    board[i][j] = 3;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 2) board[i][j] = 0;
                if (board[i][j] == 3) board[i][j] = 1;
            }
        }
    }
private:
    pair<int, int> checkNeighbors(vector<vector<int>>& board, int i, int j) {
        int live = 0, dead = 0;
        for (auto& [dx, dy]: directions) {
            int x = i + dx;
            int y = j + dy;
            if (x < board.size() && y < board[0].size()) {
                if (board[x][y] == 1 || board[x][y] == 2) live++;
                else dead++;
            }
        }
        return {live, dead};
    }
};
/*
Births and deaths occur simultaneously -> cannot use the updated status to update other cells
How to solve in place without using extra space? 
Self define other status
val: original -> new
0: dead -> dead (unchanged)
1: live -> live (unchanged)
2: live -> dead
3: dead -> live
in that case, we can remember the original status & new status without using extra space

Algo:
Go through all cells
    update status based on its neighbors original status
    keep both original & new status
Convert the new status to 0 / 1
*/