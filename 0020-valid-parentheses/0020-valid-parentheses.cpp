class Solution {
public:
    bool isValid(string s) {
        stack<char> char_st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                char_st.push(c);
            } else if ( !char_st.empty() && ((c == ')' && char_st.top() == '(') || (c == '}' && char_st.top() == '{') || (c == ']' && char_st.top() == '[')) ) {
                char_st.pop();
            } else {
                return false;
            }
        }
        if (char_st.empty()) {
            return true;
        } else {
            return false;
        }
    }
};

/*
[{}()]
we can use a stack to record the string by order
becasue the stack is last in first out, this is the rule we need
when encountering a open char, we put it in.
when encountering a close char, we check if the top one can match.

*/