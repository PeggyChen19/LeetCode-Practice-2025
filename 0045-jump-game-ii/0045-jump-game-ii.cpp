class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0, n = nums.size();
        int curFarthest = 0, nextFarthest = 0;
        for (int i = 0; i < n - 1; i++) {
            nextFarthest = max(nextFarthest, i + nums[i]);
            if (i == curFarthest) {
                count++;
                curFarthest = nextFarthest;
            }
        }
        return count;
    }
};
/*
Target: min jumps to reach nums[n-1]
DP / Greedy -> Greedy can do it, don't need DP
Concept: keep finding the point which can go farthest
*/