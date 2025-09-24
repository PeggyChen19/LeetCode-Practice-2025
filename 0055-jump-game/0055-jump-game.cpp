class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReachable = 0, i = 0;
        while (i <= maxReachable) {
            maxReachable = max(maxReachable, i + nums[i]);
            if (maxReachable >= nums.size() - 1) return true;
            i++;
        }
        return false;
    }
};
/*
Greedy
while (i <= maxReachable)
    update maxReachable
    if maxReachable >= size - 1
        return true
return false
*/