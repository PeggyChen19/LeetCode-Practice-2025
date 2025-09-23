class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int step = 1;
        int a = 0, b = 0;
        while (n > 0) {
            int digit = n % 10;
            n /= 10;
            if (n == 0 || (digit != 0 && digit != 1)) {
                a += (digit - 1) * step;
                b += step;
            } else {
                digit += 10;
                a += (digit - 5) * step;
                b += 5 * step;
                n--;
            }
            step *= 10;
        }
        return {a, b};
    }
};
/*
do it digit by digit from low to high
for each digit, try to find the pair not having 0
if digit is highest OR (digit != 0 AND digit != 1): easy! {digit - 1, 1}
else: treat digit as 10 OR 11, borrow carry from higher digit

int step = 1
while n > 0
    digit = n % 10
    n /= 10
    if (highest digit || (digit != 0 && digit != 1)) {
        digitA += (digit - 1) * step
        digitB += step
    } else {
        // treat it as 10 or 11, borrow carry from higher digit
        digit += 10
        digitA = (digit - 5) * step
        digitB = 5 * step
        n--
    }
    step *= 10
*/