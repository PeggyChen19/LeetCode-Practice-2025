class Solution {
public:
    double myPow(double x, int n) {
        double result = 1.0;
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        while (n) { // process n bit by bit (2 based)
            if (n % 2 == 1) { // the least significant bit is 1
                result *= x; // include this power of x to the result
            }
            x *= x; // square x to represent the next power of two
            n = n >> 1; // divide by 2
        }
        return result;
    }
};
/*
For n < 0 -> transfer x
3^13 
= 3^(1101)2 based
= 3^8 * 3^4 * 3^1
*/