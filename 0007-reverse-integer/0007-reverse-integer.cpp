class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;
        int result = 0;
        while (x != 0) {
            int lastDigit = x % 10;
            if ((lastDigit > 0 && result > INT_MAX / 10) || (lastDigit < 0 && result < INT_MIN / 10)) return 0; // overflow (no equal)
            else result *= 10;
            if ((lastDigit > 0 && result > INT_MAX - lastDigit) || (lastDigit < 0 && result < INT_MIN - lastDigit)) return 0; // overflow
            else result += lastDigit;
            x /= 10;
        }
        return result;
    }
};
/*
notice of overflow
int result = 0
while (x > 0)
    result = result * 10 + (x % 10) (check overflow)
    x /= 10
*/