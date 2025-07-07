class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int globalMin = n + 1;
        int left = 0, curSum = 0;
        for (int right = 0; right < n; right++) {
            curSum += nums[right];
            while (curSum >= target) {
                globalMin = min(globalMin, right - left + 1);
                curSum -= nums[left];
                left++;
            }
        }
        return globalMin == n + 1 ? 0: globalMin;
    }
};
/*
Sliding Window
use int globalMin to track the current min len
while right != end
    Keep expanding right until sum >= target
    Shrinking left until not satisfy
*/