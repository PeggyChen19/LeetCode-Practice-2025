class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = nums[0] + nums[1] + nums[2]; // len(nums) >= 3
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int remain = target - nums[i];
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int twoSum = nums[left] + nums[right];
                if (twoSum == remain) {
                    return target;
                } else if (twoSum > remain) { // make two sum smaller
                    right--;
                } else { // make two sum bigger
                    left++;
                }
                if (abs(remain - twoSum) < abs(target - result)) { // find better result
                    result = nums[i] + twoSum;
                }
            }
        }
        return result;
    }
};
/*
3 Sum closest to the target
Only have exactly one solution.
---
1. sort the array: O(nlogn)
2. choose the first num
    a. use two pointers find the remaining two nums (make it closest to target)
Time Complexity: O(n^2)
*/