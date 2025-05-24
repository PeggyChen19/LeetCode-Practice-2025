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

curFarthest: the end of the current jump range. 
             When we reach this point, we must jump, and update it to nextFarthest.

nextFarthest: the farthest point we can reach within the current range.
              It keeps updating as we explore positions inside the current jump range.

We scan from left to right, always tracking the farthest point we can reach (nextFarthest). When we reach the end of the current range (curFarthest), we must make a jump, and update curFarthest to nextFarthest.
*/