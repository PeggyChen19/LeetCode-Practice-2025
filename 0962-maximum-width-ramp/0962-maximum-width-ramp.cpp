class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return -1;
        int result = 0;
        vector<int> decreasing; // index
        for(int i = 0; i < nums.size(); i++) {
            if (decreasing.empty() || nums[decreasing.back()] > nums[i]) {
                decreasing.push_back(i);
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!decreasing.empty() && nums[decreasing.back()] <= nums[i]) {
                result = max(result, i - decreasing.back());
                decreasing.pop_back();
            }
        }
        return result;
    }
};
/*
From left to right, we only need to focus on decreasing part, because the bigger value can't make bigger ramp
1. find the decreasing part (non-continuous) from left to right -> build a vector to record it
2. go through the nums from right to left
    while (nums[vec.back()] <= nums[i]])
        update result
        vec.pop_back
*/