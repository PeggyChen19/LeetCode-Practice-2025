class Solution {
public:
    int trap(vector<int>& h) {
        int n = (int)h.size(), l = 0, r = n - 1;
        int leftMax = 0, rightMax = 0, ans = 0;
        while (l < r) {
            if (h[l] <= h[r]) {
                leftMax = max(leftMax, h[l]);
                ans += leftMax - h[l];
                ++l;
            } else {
                rightMax = max(rightMax, h[r]);
                ans += rightMax - h[r];
                --r;
            }
        }
        return ans;
    }
};
/*

*/