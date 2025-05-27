class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x) {
            int last_digit = x % 10; // get the last digit
            x /= 10; // remove the last digit
            // overflow check
            if (last_digit > 0 && ans > (INT_MAX - last_digit) / 10) return 0;
            if (last_digit < 0 && ans < (INT_MIN - last_digit) / 10) return 0;
            ans *= 10; // reserve the last digit place for the incoming digit
            ans += last_digit;
        }
        return ans;
    }
};
/*
321 -> 123
120 -> 21
How to handle overflow? Check it before calculating

int ans = 0
while (input) {
    int last_digit = input % 10 // get the last digit
    input /= 10 // remove the last digit
    ans *= 10 // reserve the last digit place for the incoming digit
    ans += last_digit
}
return ans
*/