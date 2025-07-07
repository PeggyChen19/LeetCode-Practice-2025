class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN, minPrefixSum = 0, curPrefixSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            curPrefixSum = curPrefixSum + nums[i];
            result = max(result, curPrefixSum - minPrefixSum);
            minPrefixSum = min(minPrefixSum, curPrefixSum);
        }
        return result;
    }
};
/*
Subarray Sum-> DP / Sliding Window / Prefix Sum
Not Sliding Window -> Not work, can't move the pointers simply based on the current states
Prefix Sum: calculate the prefix sum and go through it, calculate curPrefixSum - minPrefixSum
*/