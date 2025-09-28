class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        int remainder = num % 9;
        return remainder == 0 ? 9 : remainder;
    }
};
/*
num = d1 * 10^n + d2 * 10^n-1 + ... dn * 10^0
mod 9 for each element
num = d1 + d2 + .... dn
*/