class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax = nums[0], curMin = nums[0], globalMax = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int a = curMax * nums[i];
            int b = curMin * nums[i];
            curMax = max({nums[i], a, b});
            curMin = min({nums[i], a, b});
            globalMax = max(globalMax, curMax);
        }
        return globalMax;
    }
};
/*
subarray (continuous) -> Sliding Winodw or DP
not Sliding Window, becasue we don't have a fixed condition to follow
DP
States: index, curMax, curMin

Transition:
use global_max to record ans
candidates = nums[i], curMax[i-1] * nums[i], curMin[i-1] * nums[i]
curMax[i] = max(candidates)
curMax[i] = min(candidates)

Base case:
curMax[0] = nums[0]
curMin[0] = nums[0]

Memorization:
int curMax, curMin
*/