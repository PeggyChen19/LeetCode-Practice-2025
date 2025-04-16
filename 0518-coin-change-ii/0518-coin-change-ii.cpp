class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<uint64_t> dp(amount + 1, 0);
        dp[0] = 1;
        for (int coin : coins) {
            for (int s = coin; s < dp.size(); s++) {
                dp[s] += dp[s - coin];
            }
        }
        return dp.back();
    }
};
/*
[1, 2, 3], 4
1, 1, 1, 1
1, 1, 2
1, 3
2, 2
-> 4

States: index, current sum
Sub-problem: current sum from combinations of coins 0~i
Decision: choose it n times or not choose it
Base case:
dp[-1][0] = 1
dp[-1][1~n] = 0

Transition function:
dp(i, sum) = dp(i-1, sum) + dp(i, sum-coins[i])
             ^ not choose   ^ choose it (maybe more than once)

Memorization:
2D array: index size * target sum
Optimization: we only need one row represents i-1 & i
*/