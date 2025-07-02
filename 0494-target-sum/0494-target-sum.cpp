class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // calculate new target
        int totalSum = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }
        if ((target + totalSum) % 2) return 0;
        target = (target + totalSum) / 2;
        // find subset sum to new target;
        int negPrefix = 500;
        vector<int> dp(1501, 0); // -500~1000
        dp[negPrefix] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = target; j >= nums[i]; j--) {
                dp[j + negPrefix] += dp[j - nums[i] + negPrefix];
            }
        }
        return dp[target + negPrefix];
    }
};
/*
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000
Brute force: backtracking -> go through all possibilities
Can we use DP to reduce time complexity?
針對每個數字，都要選擇是 Positive or Negative -> Divide into 2 group
決定一個 group 後，剩下的都屬於另一個 group -> 找出其中一個 group 成立的條件
sum(P) - sum(N) = target
sum(P) + sum(N) = totalSum
---------------------------
sum(P) = 1/2 * (target + totalSum)
Transfer the problem into subset sum -> Solve by DP 0/1 Knapsack problem

Subproblem: the ways to sum up to sum from nums[0~i]
Transition function:
dp[i][sum] = dp[i-1][sum] + dp[i-1][sum - nums[i]]
Memorization:
1D vector (size: new target + 1)
*/