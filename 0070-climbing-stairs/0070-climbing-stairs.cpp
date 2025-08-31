class Solution {
public:
    int climbStairs(int n) {
        int pre1 = 1, pre2 = 0;
        for (int i = 1; i <= n; i++) {
            int cur = pre1 + pre2;
            pre2 = pre1;
            pre1 = cur;
        }
        return pre1;
    }
};
/*
the i step ways = (i - 1) + (i - 2)
*/