class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, pointer = 0;
        while (i < nums.size()) {
            if (nums[i] != 0) {
                swap(nums[i], nums[pointer]);
                pointer++;
            }
            i++;
        }
    }
};
/*
do it in-place -> swap
use a pointer to record the first element after the processed array
1 0 0 2 3 0 4
  ^   *
1 2 0 0 3 0 4
    ^   *
*/