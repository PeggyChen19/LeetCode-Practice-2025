class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, 0);
        dp[0] = grid[0][0];
        for (int j = 1; j < n; j++) {
            dp[j] = dp[j - 1] + grid[0][j];
        }
        for (int i = 1; i < m; i++) {
            dp[0] += grid[i][0];
            for (int j = 1; j < n; j++) {
                dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
            }
        }
        return dp[n - 1];
    }
};
/*
Shortest path -> DP
for each cell, calculate the minPath sum
Transition Function:
sum[i][j] = min(sum[i][j-1], sum[i-1][j]) + grid[i][j]
Base Case:
sum[0][j] = sum[0][j-1] + grid[0][j]
Memorization:
1D vector
*/