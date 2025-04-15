class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool first_col_zero = false;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                first_col_zero = true; // update col_first
            }
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0; // col
                    matrix[i][0] = 0; // row
                }
            }
        }
        for (int i = m - 1; i >= 0; i--) { // update from back
            for (int j = n - 1; j >= 1; j--) { // skip the first col
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            if (first_col_zero) { // handle the first col in the end
                matrix[i][0] = 0;
            }
        }
    }
};
/*
0 1 0
1 1 0
1 1 1

0 0 0
0 0 0
0 1 0 

Space: constant
1. Go thourgh each row & each column
2. Record if this row/col has 0 at the beginning of the the row/col
   row[0] and col[0] are duplicate -> create a var col_first to record col[0]
3. Mark elemements to be zero according to 2.
*/