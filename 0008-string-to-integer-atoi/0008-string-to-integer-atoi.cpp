class Solution {
public:
    int myAtoi(string s) {
        bool negative = false;
        int result = 0;
        int i = 0, n = s.size();
        while (i < n) {
            if (s[i] != ' ') break;
            i++;
        }
        if (s[i] == '+' || s[i] == '-') {
            negative = (s[i] == '-');
            i++;
        }
        while (i < n && s[i] >= '0' && s[i] <= '9') { 
            int digit = s[i] - '0';
            if ((result > 0 && result > (INT_MAX - digit) / 10) || (result < 0 && result < (INT_MIN + digit) / 10)) {
                return result > 0 ? INT_MAX : INT_MIN;
            } else {
                result = result * 10;
                result += negative ? -digit : digit;
            }
            i++;
        }
        return result;
    }
};
/*
result = 0
ignore leading white spaces
check + or -
while s[i] in [0, 9]
    int digit = s[i] - '0'
    if ((result > 0 && result < (INT_MAX - digit) / 10) || (result < 0 && result < (INT_MIN + digit) / 10))
        overflow // if result == 0, don't need to check overflow
    else 
        result = result * 10 + (char-'0') % 10
*/