class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] > target) j--;
            else i++;
        }
        return false;
    }
};
/*
Directional search
<--decrease---- *
1 4 7 11 15 20 30 |
2 5 8 12 19 25 35 |increase

start from top right, we can shrink the range efficiently by checking the relationship between cur & target
if cur > target: go left
if cur < target: go down

Time: O(m + n)
*/