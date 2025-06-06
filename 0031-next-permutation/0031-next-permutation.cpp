class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty()) return;
        int n = nums.size(), i = -1;
        for (i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                for (int j = n - 1; j >= i + 1; j--) {
                    if (nums[j] > nums[i]) {
                        swap(nums[j], nums[i]);
                        break;
                    }
                }
                break;
            }
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};
/*
1 2 5 3 2 1
  * <----->
    descending
1 2 1 2 3 5
  * <----->
    ascending
1 3 1 2 2 5
  *     ^

Target: do the min changes to make the nums bigger
The right part which is descending cannot be bigger via swapping
-> need to find the pivot and make the pivot position bigger

1. Start from right, find the first nums[i] < nums[i + 1] (pivot)
2. Start from right, find the first nums[j] > nums[i], swap(nums[i], nums[j])
3. reverse the right part [i + 1, end] (descending to ascending)
*/