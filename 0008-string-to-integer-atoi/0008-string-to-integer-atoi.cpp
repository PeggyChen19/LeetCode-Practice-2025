class Solution {
public:
    int myAtoi(string s) {
        bool positive = true;
        int i = 0, n = s.size(), result = 0;
        int maxLimit = INT_MAX / 10, minLimit = INT_MIN / 10;
        while (i < n && s[i] == ' ') {
            i++;
        }
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') positive = false;
            i++;
        }
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            if (positive && (result > maxLimit || (result == maxLimit && s[i] - '0' >= 7))) {
                return INT_MAX;
            }
            if (!positive && (-result < minLimit || (-result == minLimit && s[i] - '0' >= 8))) {
                return INT_MIN;
            }
            result *= 10;
            result += (s[i] - '0');
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