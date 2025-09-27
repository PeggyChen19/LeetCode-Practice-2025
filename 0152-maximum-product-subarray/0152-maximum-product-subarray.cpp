class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int global_max = nums[0], negative_min = 0, positive_max = 0;
        for (int num : nums) {
            if (num < 0) {
                int original_positive_max = positive_max;
                positive_max = negative_min * num;
                negative_min = min(original_positive_max * num, num);
            } else {
                negative_min = negative_min * num;
                positive_max = max(positive_max * num, num);
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