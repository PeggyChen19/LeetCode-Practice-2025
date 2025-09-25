class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }    
};
/*
2^x in binary form only have one 1, and other bits must be zero
(2^x - 1) will make that 1 become 0 and make all right part of the new 0s become 1s
00100 -> 2^x
00011 -> 2^x - 1

001100 -> not 2^x
001011

if n & (n - 1) == 0 -> n must be 2^x
edge case: if n == 0, return false;
*/