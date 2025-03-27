class Solution {
	public:
		int coinChange(vector<int>& coins, int amount) {
			if (amount == 0) {
				return 0;
			}
			vector<int> dp(amount + 1, -1); // 0~amount
			// initialize
			dp[0] = 0;
			int init = coins[0], i = 1;
			while (init*i <= amount) { 
				dp[init*i] = i;
				i++;
			}
			// dp
			for (int i = 1; i < coins.size(); i++) {
				for (int j = coins[i]; j <= amount; j++) { // j-coins[i] >= 0
					if (dp[j - coins[i]] != -1) { // exist solution
						if (dp[j] != -1) { // both has solution -> use min to decide
							dp[j] = min(dp[j], dp[j - coins[i]] + 1);
						} else {
							dp[j] = dp[j - coins[i]] + 1;
						}
					}
				}
			}
			return dp[amount];
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
	// if w(i, s-coint[i] == -1), w(i, s) == w(i-1, s)
	4. Base Case
	w(0, 0) = 0
	w(0, 1~amount) = -1
	w(0, coins[0]*n) = n
	5. Computational Sequence (bottom-up / top-down)
	bottom-up: double for loop: index & amount
	6. Memorization - build a lookup table
	dp[index][amount] table
	-> optimize to dp[amount] because we only need i-1 & i
	update dp[amount] from head
	*/