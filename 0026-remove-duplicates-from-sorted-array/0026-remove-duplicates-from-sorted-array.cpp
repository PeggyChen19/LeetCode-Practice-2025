class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int lastValid = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[lastValid] != nums[i]) {
                lastValid++;
                swap(nums[lastValid], nums[i]);
            }
        }
        return lastValid + 1;
    }
};
/*
use a pointer to record the end of the valid nums
compare the last valid num with the current num
*/