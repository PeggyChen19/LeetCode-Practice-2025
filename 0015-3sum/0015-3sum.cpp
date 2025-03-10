class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) { // the last possible ans: s-3, s-2, s-1
            if (i - 1 >= 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) { // left must not be equal to right 
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while (left + 1 < nums.size() && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (right - 1 >= 0 && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return ans;
    }
};

/*
sort the array -> O(nlogn)
set a starting point to be the fixed value and go through the array 
    set left(fixed + 1) and right(end) pointers
    based on the sum of left & right to adjust left and right
    store the new answers
return all answers
*/