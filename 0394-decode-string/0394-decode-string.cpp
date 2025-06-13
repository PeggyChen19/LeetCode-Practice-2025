class Solution {
public:
    string decodeString(string s) {
        stack<int> repeatSt;
        stack<string> strSt;
        string curStr = "";
        int i = 0;
        while (i < s.size()) {
            int repeat = 0;
            while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                repeat = repeat * 10 + (s[i] - '0');
                i++;
            }
            if (repeat != 0) {
                repeatSt.push(repeat);
                strSt.push(curStr);
                curStr = "";
            } else if (s[i] == ']'){
                string repeated = "";
                for (int j = 0; j < repeatSt.top(); j++) {
                    repeated += curStr;
                }
                curStr = strSt.top() + repeated;
                repeatSt.pop();
                strSt.pop();
            } else {
                curStr += s[i];
            }
            i++;
        }
        return curStr;
    }
};
/*
digits are only used for repeating
output not exceed 10^5 -> no overflow
3[a2[bc]]

Nested structure: recursion / stack
Encouter k[
1. store k & preStr
2. create curStr (enter a new layer to update curStr)

Encounter ]
1. repeat curStr with k times
2. preStr += curStr
3. curStr = preStr

We need two stack to record the multiple previous k and preStr
*/