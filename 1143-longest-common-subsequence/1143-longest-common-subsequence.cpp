class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text2.size() > text1.size()) { // let text2 be the shorter one
            swap(text1, text2);
        }
        vector<vector<int>> dp(2, vector<int>(text2.size()+1, 0));
        for (int i = 0; i < text1.size(); i++) {
            for (int j = 0; j < text2.size(); j++) {
                if (text1[i] == text2[j]) {
                    dp[1][j+1] = dp[0][j] + 1;
                } else {
                    dp[1][j+1] = max(dp[0][j+1], dp[1][j]);
                }
            }
            dp[0] = dp[1];
        }
        return dp[0][text2.size()];
    }
};
/*
"abce", "acebf" -> 3 ("ace")

State: t1.index, t2.index, cur_max_len
Subproblem: the max len from 0 ~ t1.ind, t2.ind
Decision:
1. [i, j] match -> [i-1, j-1] +1
2. [i, j] not match -> max([i-1, j], [i, j-1])
Implementation:
Bottom-up
Memorization:
dp[t1+1 * t2+1]
    a c e b f
  0 0 0 0 0 0
a 0 1 1 1 1 1
b 0 1 1 1 2 2
c 0 1 2 2 2 2
e 0 1 2 3 3 3
Optimization: dp[2][t2+1] -> let shorter text be t2
*/