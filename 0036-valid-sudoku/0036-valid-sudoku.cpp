class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int s = board.size();
        for (int i = 0; i < s; i++) { // each row
            if (!validate(i, i, 0, s - 1, board)) {
                return false;
            }
        }
        for (int j = 0; j < s; j++) { // each col
            if (!validate(0, s-1, j, j, board)) {
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
        vector<bool> record(10, false);
        for (int i = top; i <= down; i++) {
            for (int j = left; j <= right; j++) {
                if(record[board[i][j]]) {
                    return false;
                }
                record[board[i][j]] = true;
            }
        }
        return true;
    }
}
/*
vector<bool> record(10, false)
function validate(top, down, left, right) // range
    for all element in range
        check if num[board[i][j]] exists or not
for each row
    validate
for each col
    validate
for each square
    validate
Time: O(m*n*3)
Space: O(1)
*/