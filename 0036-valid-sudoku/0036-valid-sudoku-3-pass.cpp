class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int s = board.size();
        for (int i = 0; i < s; i++) { // each row
            if (!validate(i, i, 0, s - 1, board)) {
                return false;
            }
            if (!validate(0, s-1, i, i, board)) { // each col
                return false;
            }
        }
        for (int i = 0; i < s; i+=3) {
            for (int j = 0; j < s; j+=3) {
                if (!validate(i, i+2, j, j+2, board)) {
                    return false;
                }
            }
        }
        return true;
    }
private: 
    bool validate(int top, int down, int left, int right, vector<vector<char>>& board) {
        vector<bool> record(9, false);
        for (int i = top; i <= down; i++) {
            for (int j = left; j <= right; j++) {
                if (board[i][j] != '.') {
                    if(record[board[i][j] - '1']) {
                        return false;
                    }
                    record[board[i][j] - '1'] = true;
                }
            }
        }
        return true;
    }
};
/*
vector<bool> record(9, false)
function validate(top, down, left, right) // range
    for all element in range
        check if num[board[i][j]] exists or not
for each row
    validate
for each col
    validate
for each square
    validate
Time: O(9*9*3)
Space: O(9)
*/