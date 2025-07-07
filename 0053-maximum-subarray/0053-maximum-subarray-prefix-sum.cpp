class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN, curPrefixSum = 0, minPrefixSum = 0;
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
Prefix Sum: maxSubArraySum = maxPrefixSum(0~i) - minPrefixSum(0~j), i > j
loop all nums
    update curPrefixSum
    update result: curPrefixSum - minPrefixSum)
    update minPrefixSum
*/