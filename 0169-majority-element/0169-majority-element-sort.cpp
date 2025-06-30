class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n / 2];
    }
};
/*
Method 1:
Go through the nums and record the frequency (unordered_map)
Time: O(n)
Space: O(n)

Method 2:
Sort the nums, the nums at (n/2) is the answer (because the result must more than half)
Time: O(nlogn)
Space: O(1)
*/