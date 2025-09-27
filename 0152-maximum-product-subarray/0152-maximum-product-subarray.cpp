class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int global_max = nums[0], cur_min = nums[0], cur_max =nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int from_max = cur_max * nums[i];
            int from_min = cur_min * nums[i];
            cur_min = min(nums[i], min(from_max, from_min));
            cur_max = max(nums[i], max(from_max, from_min));
            global_max = max(global_max, cur_max);
        }
        return global_max;
    }
};

/*
abs(bigProduct) has potential -> record both curMin & curMax
global_max -> the result we return
*/