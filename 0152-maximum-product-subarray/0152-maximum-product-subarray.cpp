class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int globalMax = nums[0], maxProduct = nums[0], minProduct = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int preMaxProduct = maxProduct, preMinProduct = minProduct;
            maxProduct = max(nums[i], max(preMaxProduct * nums[i], preMinProduct * nums[i]));
            minProduct = min(nums[i], min(preMaxProduct * nums[i], preMinProduct * nums[i]));
            globalMax = max(globalMax, maxProduct);
        }
        return globalMax;
    }
};
/*
Subarray -> DP / Sliding Window
have negative nums -> not sliding window

Subproblem: maxProduct & minProduct ends with index
Transition function:
maxProduct[i] = max(nums[i], maxProduct[i - 1] * nums[i], minProduct[i - 1] * nums[i])
minProduct[i] = min(nums[i], maxProduct[i - 1] * nums[i], minProduct[i - 1] * nums[i])
*/