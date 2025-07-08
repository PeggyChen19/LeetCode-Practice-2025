class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int result = 0, prefixSum = 0;
        unordered_map<int, int> firstPrefixSum; // prefixSum, first index where the sum occurred
        firstPrefixSum[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += (nums[i] == 1 ? 1 : -1);
            if (firstPrefixSum.count(prefixSum)) {
                result = max(result, i - firstPrefixSum[prefixSum]);
            } else {
                firstPrefixSum[prefixSum] = i;
            }
        }
        return result;
    }
};
/*
Subarray -> Sliding Window / DP / Prefix Sum
Not Sliding Window -> can't decide to shrink or expand simply based on current states
Not DP -> no optimal substructure -> 子問題的結果無法組合成大問題的解

Prefix Sum:
transfer to subarray sum problem by replacing 0 with -1
try to find the longest subarray sums to 0

int result = 0
unordered_map<int, int> firstPrefixSum // prefixSum, first index where the sum occurred
loop nums
    calculate prefixSum (1 -> +1, 0 -> -1)
    update result based on (i - firstPrefixSum[prefixSum])
    update firstPrefixSum
*/