class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> memo; //sum : count
        if (nums.size() == 0) {
            return 0;
        }
        memo[nums[0]] += 1;
        memo[-nums[0]] += 1;
        for (int i = 1; i < nums.size(); i++) {
            unordered_map<int, int> next;
            for (auto [sum, count] : memo) {
                next[sum + nums[i]] += memo[sum];
                next[sum - nums[i]] += memo[sum];
            }
            memo = next;
        }
        return memo[target];
    }
};
/*
We would like to divide and conquer this question
1. state & subproblem
    sub-solution: the possible ways of index 0~i to get sum
    state: index, sum
2. decision
    for each num, we can choose add it positive or negative
3. state transition funciton
    dp(i, sum+nums[i]) += dp(i-1, sum)
    dp(i, sum-nums[i]) += dp(i-1, sum)
4. base case
    dp(0, sum) = 1
    dp(0, -sum) = 1
5. computational sequence
    we can use double loops to iterate all nums and all current possible sum
6. memorization
    we can memorize dp(i, sum) and use it later
    unordered_map<sum, count>> // this is all the possible sum for 0~i nums

*/