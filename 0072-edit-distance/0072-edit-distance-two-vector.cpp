class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(2, vector<int>(n + 1, 0));
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        int pre = 0, cur = 1;
        for (int i = 1; i <= m; i++) {
            dp[cur][0] = i;
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) { // matched
                    dp[cur][j] = dp[pre][j - 1];
                } else { // unmatched
                    dp[cur][j] = min(dp[cur][j - 1], min(dp[pre][j], dp[pre][j - 1])) + 1; // insert, remove, replace
                }
            }
            swap(pre, cur);
        }
        return dp[pre][n];
    }
};
/*
states: word1.ind(i), word2.ind(j), min_operations
Decision:
1. insert
2. remove
3. replace(modify)
4. ignore(matched)

base case:
dp[i, 0] = i (word1[0~i-1] -> size: i)
dp[0, j] = j

transition function:
dp[i, j]: word1[0 ~ i-1] & word2[0 ~ j-2]
matched: dp[i-1, j-1]
not match: get min from the following
insert: dp[i, j-1] + 1 // insert word2[j-1] to word1 -> remaining needs to match word1[0~i-1] & word2[0~j-2]
remove: dp[i-1, j] + 1 // remove word1[i-1] from word1 -> remaining needs to match word1[0~i-2] & word2[0~j-1]
replace: dp[i-1, j-1] + 1 // replace word1[i-1] with word2[j-1] -> remaining needs to match word1[0~i-2] & word2[0~j-2]

Implementation: Bottom up (double loops)

Memorization:dp size: 2 * word2.size()+1
*/