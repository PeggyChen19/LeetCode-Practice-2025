class Solution {
public:
    int countSubstrings(string s) {
        int result = 0, n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, false));
        for (int end = 0; end < n; end++) {
            for (int start = 0; start <= end; start++) {
                if (s[start] == s[end] && ((end - start + 1 <= 2) || dp[start+1][end-1])) {
                    dp[start][end] = true;
                    result++;
                }
            }
        }
        return result;
    }
};
/*
Number of palindromic substrings
Substring -> DP
States: index, curAns
int result = 0
for cur_char in string
    for (i = 0 ~ cur_char-1)
        if (panlindromic(i, cur))
            result++
            update dp

Memorization:
vector<vector<bool>> dp; // dp[i][j] is panlindromic or not

Complexity:
Time: O(n^2)
Space: O(n^2)
*/