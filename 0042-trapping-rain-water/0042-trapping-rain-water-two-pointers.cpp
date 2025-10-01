class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int ans = 0;
        int l = 0, r = height.size() - 1;
        int leftMax = height[l], rightMax = height[r];
        while (l <= r) {
            // update max on both side
            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);
            if (leftMax < rightMax) { // the limit is left
                ans += (leftMax - height[l]); // it will have a higher right wall in the future -> add the current result
                l++;
            } else {
                ans += (rightMax - height[r]);
                r--;
            }
        }
        return ans;
    }
};
/*
the water we can store always decide by the lower wall
use two pointers from both ends, record the leftMax & rightMax

while l <= r
    update leftMax & rightMax
    if leftMax < rightMax // the limit is left
        ans += (leftMax - height[l]) // it will have a higher right wall in the future -> add the current result
        l++
    else
        ans += (rightMax - height[r])
        r--
return ans
*/