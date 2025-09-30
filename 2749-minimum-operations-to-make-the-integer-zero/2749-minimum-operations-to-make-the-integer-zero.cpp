class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if (num1 == 0) return 0;
        for (int k = 1; k <= 60; k++) {
            long long x = num1 - 1LL * k * num2;
            if (x <= 0) { // can't have 2^i1 + 2^i2 ...
                continue;
            }
            int bits = oneCounts(x); // number of 1s in binary form
            if (bits <= k && k <= x) {
                return k;
            }
        }
        return -1;
    }
private:
    int oneCounts(long long x) {
        int count = 0;
        while (x > 0) {
            if (x & 1) {
                count++;
            }
            x >>= 1;
        }
        return count;
    }
};
/*
i from 0 to 60
num1 = (2^i1 + 2^i2 + ... + 2^ik) + k * num2
x = num1 - k * num2 = 2^i1 + 2^i2 + ... + 2^ik
x is the sum of k powers of two

the number of "1" in x's binary is the min number of powers of two needed
2^i must have at least one "1" -> k <= x

oneCounts(x) <= k <= x, this is the range of k
*/