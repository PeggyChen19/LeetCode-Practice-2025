class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int result = INT_MIN, minPrefixSum = 0;
        vector<int> prefixSum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
            result = max(result, prefixSum[i] - minPrefixSum);
            minPrefixSum = min(minPrefixSum, prefixSum[i]);          
        }
        return result;
    }
};
/*
Subarray Sum-> DP / Sliding Window / Prefix Sum
Not Sliding Window -> Not work, can't move the pointers simply based on the current states
Prefix Sum: calculate the prefix sum and go through it, calculate curPrefixSum - minPrefixSum
*/