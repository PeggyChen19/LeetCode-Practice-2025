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
No overflow problem
-----
Key: * and / before + and -

Scan the string from left to right
Original solution: use stack, but it need O(n) space
Improvement with O(1) space: use variables "result" & "subResult"(the same function as stack.top)
Also store curVal & preOper (the oper before curVal)
(+) 1 + 2 * 3
calcualte curVal until meeting non-digit
if preOper == * or / -> calculate with subResult
    subResult *= or /= curVal
if preOper == + or - -> update the result and clear subResult for the future calculate
    result += subResult
    subResult = +-curVal
*/