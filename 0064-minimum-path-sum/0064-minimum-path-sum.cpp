class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n + 1, INT_MAX);
        dp[1] = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[j + 1] = min(dp[j], dp[j + 1]) + grid[i][j];
            }
        }
        return dp[n];
    }
};
/*
Shortest path -> DP
for each cell, calculate the minPath sum
Transition Function:
sum[i][j] = min(sum[i][j-1], sum[i-1][j]) + grid[i][j]
Memorization:
1D vector
*/