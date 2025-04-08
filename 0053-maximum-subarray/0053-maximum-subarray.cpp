class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int global_max = INT_MIN;
        int cur_max = 0;
        for (int num : nums) {
            cur_max = max(num, num + cur_max);
            global_max = max(global_max, cur_max);
        }
        return global_max;
    }
};
/*
State: i (end of the subarray), max_sum
Subproblem: the max sum end with i
這邊不要把 start point 當作 state，因為決定 start point 的時候還不能確定 max_sum，這樣就沒意義了
通常要 memorize 的東西就是大問題在問的東西
Decision:
1. Ignore previous, start from this point
2. Include previous and this point
Transition function:
init: ans = -INF
dp[i] = max(nums[i], dp[i-1] + nums[i])
ans = max(ans, dp[i])
要注意這邊 dp[size-1] 不一定會是答案，因為他的定義是以 i 為結尾的最大可能，但最好的 subarray 不一定以 size-1 結尾，所以要用 ans 記錄目前最好的
Implement:Bottom-up
Memorization:
Two vars: prev, ans
*/