class Solution {
public:
    int myAtoi(string s) {
        bool positive = true;
        int i = 0, n = s.size(), result = 0;
        while (i < n && s[i] == ' ') {
            i++;
        }
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') positive = false;
            i++;
        }
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';
            if (result > (INT_MAX - digit) / 10) {
                return positive ? INT_MAX : INT_MIN;
            }
            result *= 10;
            result += digit;
            i++;
        }
        return positive ? result : -result;
    }
};
/*
Procedure:
1. Ignore leading whitespace
2. Determine Signedness (+ / -)
3. Ignore leading zero
4. Read numbers unitl encountering non-digit
    - Round to 32 bits range
*/