class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int result = 0, prefixSum = 0;
        unordered_map<int, int> prefixSumInd; // prefixSum from 0 ~ i
        prefixSumInd[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += (nums[i] == 1 ? 1 : -1);
            if (prefixSumInd.count(prefixSum)) {
                result = max(result, i - prefixSumInd[prefixSum]);
            } else {
                prefixSumInd[prefixSum] = i;
            }
        }
        return result;
    }
};
/*
Subarray -> Sliding Window / DP / Prefix Sum
Not Sliding Window -> can't decide to shrink or expand simply based on current states

Not DP -> no overlapping subproblems

Prefix Sum:
transfer to subarray sum problem by replacing 0 with -1
try to find the longest subarray sums to 0

int result = 0
unordered_map<int, int> prefixSumInd // prefixSum, min ind where this sum occurred
loop nums
    calculate prefixSum (1 -> +1, 0 -> -1)
    update result based on (i - prefixSumInd[prefixSum] + 1)
    update prefixSumInd
*/