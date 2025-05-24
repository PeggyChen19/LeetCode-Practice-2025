class Solution {
public:
    int jump(vector<int>& nums) {
        int i = 0, visited = 0, count = 0, n = nums.size();
        while (i < n - 1) { // not reach the end
            count++;
            int farthestPoint = i, farthest = 0;
            int reachableRange = min(i + nums[i], n - 1);
            if (reachableRange >= n - 1) {
                break;
            }
            for (int step = visited + 1; step <= reachableRange; step++) {
                if (step + nums[step] > farthest) {
                    farthestPoint = step;
                    farthest = step + nums[step];
                }
            }
            i = farthestPoint;
            visited = reachableRange;
        }
        return count;
    }
};
/*
Target: min jumps to reach nums[n-1]
DP / Greedy -> Greedy
For current i, choose the point which can go farthest from i to i + j
count = 0, i = 0, visited = -1
while i < n-1
    farthest = 0
    for (step = visited + 1; step <= i+nums[i]; step++)
        farthest = max(step + nums[step], farthest)
    i = farthest
    count++
    visited = i + nums[i] // avoid duplicated calculation

Time Complexity: O(n)
       0 1 2 3 4
nums   2 3 1 1 4 
farest   4 3 v
             4 8
*/