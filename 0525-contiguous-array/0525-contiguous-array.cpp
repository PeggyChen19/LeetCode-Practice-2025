class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLen = 0, curPrefixSum = 0;
        unordered_map<int, int> firstPrefixSum; // prefixSum, firstInd
        firstPrefixSum[curPrefixSum] = -1;
        for (int i = 0; i < nums.size(); i++) {
            curPrefixSum += (nums[i] == 1) ? 1: -1;
            if (firstPrefixSum.count(curPrefixSum)) {
                maxLen = max(maxLen, i - firstPrefixSum[curPrefixSum]);
            }
            if (!firstPrefixSum.count(curPrefixSum)) {
                firstPrefixSum[curPrefixSum] = i;
            }
        }
        return maxLen;
    }
};
/*
-1 -1  1  1  -1 
-1 -2 -1  0  -1
Subarray -> Sliding Window / DP / Prefix Sum
Not Sliding Window -> can't decide when to move left
Not DP -> ??
Target: find the max subarray where sum == 0 (replace 0 to -1)
interval sum = curPrefixSum - prefixSum = 0

int maxLen = 0
unordered_map<int, int> firstPrefixSum // prefixSum, firstInd
go through nums
    record curPrefixSum
    find -curprefixSum from firstPrefixSum
    update firstPrefixSum
*/