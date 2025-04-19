class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int s = board.size(); // 9 in this problem
        vector<int> row(9, 0), col(9, 0), box(9, 0);
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < s; j++) {
                char c = board[i][j];
                if (c == '.') {
                    continue;
                }
                int box_ind = (i/3) * 3 + (j/3);
                int mask = 1 << (c - '1');
                if (row[i] & mask || col[j] & mask || box[box_ind] & mask) {
                    return false;
                }
                row[i] |= mask;
                col[j] |= mask;
                box[box_ind] |= mask;
            }
        }
        return true;
    }
};
/*
Instead of use vector<int>(9, false) to record number 1~9, we can use an int
the i bit of this int represent the number i
*/