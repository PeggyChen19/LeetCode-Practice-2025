class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0]++; // no element -> prefixSum = 0
        int result = 0, curPrefixSum = 0;
        for (int num : nums) {
            curPrefixSum += num;
            if (prefixSumCount.count(curPrefixSum - k)) {
                result += prefixSumCount[curPrefixSum - k];
            }
            prefixSumCount[curPrefixSum]++;
        }
        return result;
    }
};
/*
subarray sum -> internal sum -> prefix sum
prefixSum[j] - prefixSum[i] = intervalSum[i, j] = k

use unordered_map<prefixSumVal, count> to record all prefix sum val
use int result to record result
for num in nums
    update curPrefix
    if curPrefix - k can be found in mapping
    result += mapping[curPrefix - k]
    mapping[curPrefix]++
*/