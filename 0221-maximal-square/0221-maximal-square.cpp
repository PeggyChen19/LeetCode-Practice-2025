class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int result = 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(2, vector<int>(m, 0));
		int pre = 0, cur = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
				if (j == 0) {
					dp[cur][j] = (matrix[i][j] == '1') ? 1 : 0;
				} else if (matrix[i][j] == '1') {
					dp[cur][j] = min(dp[pre][j - 1], min(dp[cur][j - 1], dp[pre][j])) + 1;
                }
				result = max(result, dp[cur][j]);
            }
			swap(pre, cur);
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
Change to 2*m DP

0 1 1 1
1 0 1 1
1 1 1 1
*/