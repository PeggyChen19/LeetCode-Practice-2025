class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        if (row == 0) return 0;

        vector<int> dp(row, INT_MAX);
        dp[0] = triangle[0][0];
        for (int i = 1; i < row; i++) {
            for (int j = i; j > 0; j--) {
                dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j];
            }
            dp[0] += triangle[i][0];
        }
        // find the min total from the last row
        int minTotal = INT_MAX;
        for (int i = 0; i < row; i++) {
            minTotal = min(minTotal, dp[i]);
        }
        return minTotal;
    }
};
/*
shortest path -> DP
for each cell, calculate the min total
dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j]
return the min total from the last row
*/