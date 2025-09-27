class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int global_max = nums[0], negative_min = min(0, nums[0]), positive_max = max(0, nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                int original_positive_max = positive_max;
                positive_max = negative_min * nums[i];
                negative_min = min(original_positive_max * nums[i], nums[i]);
            } else {
                negative_min = negative_min * nums[i];
                positive_max = max(positive_max * nums[i], nums[i]);
            }
            global_max = max(global_max, positive_max);
        }
        return global_max;
    }
};

/*
abs(bigProduct) has potential -> record it

negative_min -> become bigger when encounter negative
positive_max -> become bigger when encounter positive

global_max -> the result we return
negative_min[i]: the smallest negative product subarray ends with i
positive_max[i]: the biggest positive product subarray ends with i
we only need the previous negative_min & positive_max
*/