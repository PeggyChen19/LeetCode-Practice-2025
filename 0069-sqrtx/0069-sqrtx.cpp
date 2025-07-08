class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        int left = 1, right = x;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if ((long) mid * mid <= (long) x) { // go right
                left = mid + 1;
            } else { // go left
                right = mid - 1;
            }
        }
        // left is the first element which square > x
        return left - 1;
    }
};
/*
find square root of x rounded down to the nearest integer
rounded_down_root ** 2 <= x
(rounded_down_root + 1) ** 2 > x

Improvement: use binary search
*/