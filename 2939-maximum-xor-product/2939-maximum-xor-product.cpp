class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        int mod = 1000000007;
        // highest size - n bits should remain the same
        long long xor_a = a >> n;
        long long xor_b = b >> n;
        // shift one bit to left and then append new xor bit to the end
        for (int i = n; i > 0; i--) {
            // get the i th lowest bit of a & b
            int a_i_bit = a >> (i - 1) & 1;
            int b_i_bit = b >> (i - 1) & 1;
            if (a_i_bit == b_i_bit) {
                xor_a = xor_a << 1 | 1;
                xor_b = xor_b << 1 | 1;
            } else if (xor_a > xor_b) { // add the 1 to the b ith bit
                xor_a = xor_a << 1;
                xor_b = xor_b << 1 | 1;
            } else { // add the 1 bit to a ith bit
                xor_a = xor_a << 1 | 1;
                xor_b = xor_b << 1;
            }
        }
        return (xor_a % mod) * (xor_b % mod) % mod;
    }
};

/*
a = 12 -> b1100
b = 5  -> b0101
n = 4

x = 2    -> b0010
a ^ x = 1110 = 14
b ^ x = 0111 = 7
(a ^ x) * (b ^ x) = 98 -> answer

a & b left decided part
if a is bigger, choose b n - 2 bit be 1
vice versa

2^n -> n possible bits
x in binary should be n bits number
only care about the lowest significant n bits of a and b
take the single bit
a = 1, b = 1, x = 0
a = 1, b = 0, x = ?
a = 0, b = 1, x = ? -> decide based on the existing high bits
a = 0, b = 0, x = 1

(n bits of a^x) * (m bits of b^x)
*/