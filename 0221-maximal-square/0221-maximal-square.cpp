class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int result = 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<int> dp(m + 1, 0);
        int pre = 0;
        for (int i = 0; i < n; i++) {
            pre = 0;
            for (int j = 0; j < m; j++) {
                int tmp = dp[j + 1];
                if (matrix[i][j] == '1') {
                    dp[j + 1] = min(pre, min(dp[j], dp[j + 1])) + 1;
                    result = max(result, dp[j + 1]);
                } else {
                    dp[j + 1] = 0;
                }
                pre = tmp;
            }
        }
        return result * result;
    }
};
/*
There are multiple overlapping subproblems -> DP
States:
dp[i][j]: the maxSquareLen which bottom-right is [i][j]
Transition Function:
dp[i][j] = 0 / min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1
Base Case:
dp[i][0] = 0 / 1
dp[0][j] = 0 / 1
Space Optimization:
Change to 1*m array

0 1 1 1
1 0 1 1
1 1 1 1
*/