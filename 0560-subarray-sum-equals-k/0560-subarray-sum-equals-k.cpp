class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1; // empty array
        int prefixSum = 0, result = 0;
        for (int& num : nums) {
            prefixSum += num;
            int target = prefixSum - k;
            if (prefixSumCount.count(target)) {
                result += prefixSumCount[target];
            }
            prefixSumCount[prefixSum]++;
        }
        return result;
    }
};
/*
subarray satisfies some condition -> sliding window
But! we can't decide when to move left pointer (has positive & negative nums) -> sliding window not work
interval sum -> prefix sum
unordered_map to record the count of each prefix sum value
go through all nums
    update prefixSum
    if prefixSum - (one of previous prefixSums) == k
        update result
    update count
*/