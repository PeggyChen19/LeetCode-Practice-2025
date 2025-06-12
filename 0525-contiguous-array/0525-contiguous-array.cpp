class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLen = 0, curPrefixSum = 0;
        unordered_map<int, int> prefixSum; // prefixSum, firstInd
        prefixSum[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            curPrefixSum += (nums[i] == 1) ? 1: -1;
            if (prefixSum.count(curPrefixSum)) { // the prefixSum has existed
                maxLen = max(maxLen, i - prefixSum[curPrefixSum]); // update maxLen
            } else {
                prefixSum[curPrefixSum] = i; // record the new prefixSum
            }
        }
        return maxLen;
    }
};
/*
Subarray -> Sliding Window / DP / Prefix Sum
Not Sliding Window -> can't decide when to move left
Not DP -> ??
Target: find the max subarray where sum == 0 (replace 0 to -1)
interval sum = curPrefixSum - prefixSum = 0

int maxLen = 0
unordered_map<int, int> firstPrefixSum // prefixSum, firstInd
go through nums
    record curPrefixSum
    find curprefixSum from firstPrefixSum
    update firstPrefixSum
*/