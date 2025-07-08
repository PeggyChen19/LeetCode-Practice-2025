class Solution {
public:
    int mySqrt(int x) {
        for (int i = 1; i <= x; i++) {
            if (i > x / i) {
                return i - 1;
            }
        }
        return x;
    }
};
/*
find square root of x rounded down to the nearest integer
if (square root of x) is y -> x = y ** 2
rounded_down_y ** 2 <= x
(rounded_down_y + 1) ** 2 > x
*/