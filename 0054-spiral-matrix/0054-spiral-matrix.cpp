class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row_start = 0, row_end = matrix.size() - 1;
        int col_start = 0, col_end = matrix[0].size() - 1;
        while (row_start <= row_end && col_start <= col_end) {
            for (int i = col_start; i <= col_end; i++) { // left to right
                ans.push_back(matrix[row_start][i]);
            }
            row_start++;
            if (row_start > row_end) break;
            for (int i = row_start; i <= row_end; i++) { // top to down
                ans.push_back(matrix[i][col_end]);
            }
            col_end--;
            if (col_end < col_start) break;
            for (int i = col_end; i >= col_start; i--) { // right to left
                ans.push_back(matrix[row_end][i]);
            }
            row_end--;
            if (row_end < row_start) break;
            for (int i = row_end; i >= row_start; i--) { // down to top
                ans.push_back(matrix[i][col_start]);
            }
            col_start++;
        }
        return ans;
    }
};
/*
boundary: 
row: 0~m, col: 0~n

moving directions:
1. left to right
row.start++
2. top to down
col.end--
3. right to left
row.end--
4. down to top
col.start++
*/