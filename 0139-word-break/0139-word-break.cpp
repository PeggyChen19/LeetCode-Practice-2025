class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size(), false);
        for (int i = 0; i < s.size(); i++) {
            for (int b = -1; b < i; b++) {
                int len = i - (b+1) + 1;
                if ( (b == -1 || dp[b]) && word_set.count(s.substr(b+1, len)) ) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};
/*
States: ind, valid_ind, break_flag
Subproblem: if s[0~i] is breakable or not
Base case: dp[-1] = true

Transition function:
dp[i] |= dp[vi] && (s[vi+1~i] is in wordDict)

Implement:
for (i = 0; i < size; i++)
    for (vi = 0; vi = i, vi++)
        update dp[i]

Memorization:
vector<bool> dp(s.size(), false)
*/