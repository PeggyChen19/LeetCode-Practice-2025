class Solution {
public:
    uint32_t reverseBits(uint32_t n) {  
    uint32_t r = 0;
    for (int i = 0; i < 32; i++) {
        r = (r << 1) + (n & 1);
        n = n >> 1;
    }
    return r;
    }
};
/*
n=100111
r=111001

get the right most bit of n: right_most
left shit r and add right_most to the r
right shift n
*/