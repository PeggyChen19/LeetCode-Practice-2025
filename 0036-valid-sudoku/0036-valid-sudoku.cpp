class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int s = board.size(); // 9 in this problem
        vector<vector<bool>> row(s, vector<bool>(9, false));
        vector<vector<bool>> col(s, vector<bool>(9, false));
        vector<vector<bool>> box(s, vector<bool>(9, false));
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < s; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                int box_ind = (i/3) * 3 + (j/3);
                int num = board[i][j] - '1';
                if (row[i][num] || col[j][num] || box[box_ind][num]) {
                    return false;
                }
                row[i][num] = col[j][num] = box[box_ind][num] = true;
            }
        }
        return true;
    }
};