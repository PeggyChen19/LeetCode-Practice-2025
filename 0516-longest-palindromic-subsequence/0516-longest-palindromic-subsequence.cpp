class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string rs = s;
        int n = s.size();
        reverse(rs.begin(), rs.end());
        vector<vector<int>> dp(2, vector<int>(n + 1, 0));
        int pre = 0, cur = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i] == rs[j]) {
                    dp[cur][j + 1] = dp[pre][j] + 1;
                } else {
                    dp[cur][j + 1] = max(dp[pre][j + 1], dp[cur][j]);
                }
            }
            swap(pre, cur);
        }
        return dp[pre][n];
    }
};
/*
acbaee
eeabca
-> aba

palindromic -> 前面跟後面有 common element
翻轉 s 後，比較 s 與 reverse s 的 longest common subsequence，就會是 longest
palindromic subsequence
-> 翻轉後還能找到兩字串間相對順序不變的 common element，就是 Palindromic

dp[i][j]: LCS from s[0:i] & rs[0:j]
dp[-1][*] = dp[*][-1] = 0

if s[i] == rs[j]
    dp[i][j] = dp[i-1][j-1] + 1 // choose the common element
else
    dp[i][j] = max(dp[i][j-1], dp[i-1][j]) // inherit the current max

Space Optimization:
only use two row dp[2][j]

*/