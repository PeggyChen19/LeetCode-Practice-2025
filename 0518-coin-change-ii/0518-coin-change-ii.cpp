class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1;
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};
/*
final problem can be derived from sub-problem -> DP
vector dp, size: amount + 1, val: 0
for each coin
    for each sum (from coin to amount)
        update dp[sum] (the same coin value can use multiple times)
*/