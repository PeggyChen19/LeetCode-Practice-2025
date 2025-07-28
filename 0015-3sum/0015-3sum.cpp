class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size - 2; i++) {
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            int left = i + 1, right = size - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    do left++; while (left < right && nums[left - 1] == nums[left]);
                    do right--; while (left < right && nums[right + 1] == nums[right]);
                } else if (sum > 0) { // be smaller
                    right--;
                } else { // be bigger
                    left++;
                }
            }
        }
        return result;
    }
};
/*
fix one element, find the remaining two -> time complexity: O(n * ?)
for finding the remaining two, our target is O(n) -> two pointers -> sort the nums
Overall time complexity: O(n^2) + O(nlogn) = O(n^2)
Note: no duplicated result, every num can be selected once only
*/