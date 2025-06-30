class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0, curMin = 0, curMax = 0;
        int globalMax = nums[0], globalMin = nums[0];
        for (int& num : nums) {
            totalSum += num;
            curMin = min(num, curMin + num);
            curMax = max(num, curMax + num);
            globalMin = min(globalMin, curMin);
            globalMax = max(globalMax, curMax);
        }
        if (totalSum == globalMin) {

        }
        return (globalMax < 0) ? globalMax : max(globalMax, totalSum - globalMin);
    }
};
/*
Subarray -> Sliding Widnow / DP
We can't apply sliding window because it requires a clear condition to move the window boundaries
However, there is no fixed rule to adjust the window (there are both positive & negative values)
-> use DP

Transition function:
dp[i] = max(dp[i-1] + nums[i], nums[i]) // the max sum ends with i
Handling circular:
The max circular subarray: totalSum - minSum

Use globalMaxSum, globalMinSum to record result
return max(globalMaxSum, totalSum - globaMinSum)
Special Case: All negavite array (globalMaxSum < 0) -> return globalMaxSum
*/