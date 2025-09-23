class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int leftRange = 0, rightRange = n - 1;
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] > target) break;
            else if (target > matrix[i][n - 1]) continue;
            int left = leftRange, right = rightRange;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (matrix[i][mid] == target) return true;
                else if (matrix[i][mid] > target) right = mid - 1; // go left
                else left = mid + 1; // go right
            }
            rightRange = right; // the largest element which is smaller than target
        }
        return false;
    }
};
/*
both row & column are sorted, but they are indepedent
sorted -> binary search

columnRange = [row.begin(), row.end()]
go through each row
    // check if the row range is valid, row.begin() <= target <= row.end()
    if row.begin() > target
        break
    elif target > row.end()
        continue
    elif row.begin() <= target <= row.end()
        conduct binary search of this row in columnRange, find the target OR the largest element "upperbound" which is smaller than target
        set the binary search columnRange to [0, upperbound]
*/