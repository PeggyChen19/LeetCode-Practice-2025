class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int mid_val = matrix[mid / n][mid % n];
            if (mid_val < target) { // go right
                left = mid + 1;
            } else if (mid_val > target) { // go left
                right = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
/*
We can treat it as a 1D vector and then use binary search to achieve O(log(m*n))
*/