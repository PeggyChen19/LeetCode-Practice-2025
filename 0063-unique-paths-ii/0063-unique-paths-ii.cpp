class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0; // can't reach src or dst
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 0; i < m; i++) {
            dp[0] = (obstacleGrid[i][0] == 0 && dp[0] == 1) ? 1 : 0;
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                } else {
                    dp[j] = dp[j] + dp[j - 1];
                }
            }
        }
        return dp[n - 1];
    }
};
/*
dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
Obstacle -> dp[i][j] = 0
Memorization:
vector<int>, size: column
*/