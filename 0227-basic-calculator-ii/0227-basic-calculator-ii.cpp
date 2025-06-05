class Solution {
public:
    int calculate(string s) {
        int result = 0, subResult = 0, curVal = 0;
        char preOper = '+';
        s += "#";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') continue;
            if (s[i] >= '0' && s[i] <= '9') { // update curVal
                curVal = curVal * 10 + (s[i] - '0');
            } else { // encounter next operator
                if (preOper == '*') {
                    subResult *= curVal;
                } else if (preOper == '/') {
                    subResult /= curVal;
                } else {
                    result += subResult;
                    subResult = (preOper == '+') ? curVal : -curVal;
                }
                preOper = s[i];
                curVal = 0;
            }
        }
        result += subResult;
        return result;
    }
};
/*
Only non-negative integers, +, -, *, /, space(ignore it)
No overflow
-----
* and / before + and -
Scan the string from left to right
Record some value and operator:
result, subResult, preOper, curVal
(+) 1 + 2 * 3
if preOper == * or /
    subResult *= or /= curVal // calculate directly 
if preOper == + or -
    result += subResult // update the result and clear subResult for the future calculate
    subResult = +-curVal
*/