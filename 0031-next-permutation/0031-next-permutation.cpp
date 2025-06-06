class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool descending = true;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                reverse(nums.begin() + i + 1, nums.end());
                for (int j = i + 1; j < nums.size(); j++) {
                    if (nums[j] > nums[i]) {
                        swap(nums[j], nums[i]);
                        break;
                    }
                }
                descending = false;
                break;
            }
        }
        if (descending) {
            reverse(nums.begin(), nums.end());
        }
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
2. reverse the right part [i + 1, end] (descending to ascending)
3. From [i + 1, end], find the first nums[j] > nums[i], swap(nums[i], nums[j])

Specail case: fully descending order: reverse it (become ascending order)
*/