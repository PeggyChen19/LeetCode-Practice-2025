class Solution {
	public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        sort(coins.rbegin(), coins.rend());
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max); // 0~amount
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) { // j-coins[i] >= 0
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        return (dp[amount] >= Max) ? -1 : dp[amount];
    } 
};
/*
1. State & Subproblem
state: index, cur_sum
subproblem: the fewest number of coins to sum up to cur_sum from index 0~i
2. Decision
chose 0~infinite coins
3. State Transition Function
w(i, s) = min (w(i-1, s)    ,   w(i, s-coins[i]) + 1)
                ^ not choose     ^ choose one more this coin
4. Base Case
w(-1, 0) = 0
w(-1, 1~amount) = -1
5. Computational Sequence (bottom-up / top-down)
bottom-up: double for loop: index & amount
6. Memorization - build a lookup table
dp[index][amount] table
-> optimize to dp[amount] because we only need i-1 & i
update dp[amount] from head
*/