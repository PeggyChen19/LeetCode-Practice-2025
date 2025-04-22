class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int b = 0; b < i; b++) {
                int len = (i-1) - b + 1;
                if ( dp[b] && word_set.count(s.substr(b, len)) ) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};
/*
States: ind, break point, breakable_flag
Subproblem: if s[0~i-1] is breakable or not

Base case: dp[0] = true // empty string -> breakable

Transition function:
dp[i] ||= dp[b] && (s[b~i-1] is in wordDict)

Implement:
for (i = 1; i <= size; i++)
    for (b = 0; b < i, b++)
        update dp[i]

Memorization:
vector<bool> dp(s.size()+1, false)
*/