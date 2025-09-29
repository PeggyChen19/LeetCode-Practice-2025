class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.empty()) return -1;
        int n = nums.size(), left = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        for (int pivot = 0; pivot < n; pivot++) {
            if (left == sum - left - nums[pivot]) return pivot;
            left += nums[pivot];
        }
        return -1;
    }
};
/*
if nums.size() == 0: return -1
if nums.size() == 1: return 0

set num[0] as pivot
calcualte left part & right part
check if left part == right part
keep moving pivot, update left & right part
*/