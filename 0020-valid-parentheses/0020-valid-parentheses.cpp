class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else if ( !st.empty() && isPair(st.top(), c) ) {
                st.pop();
            } else {
                return false;
            }
        }
        return st.empty(); // clear code instead of if else
    }
private:
    bool isPair(char st_top, char cur) {
        return ( (st_top == '(' && cur == ')') || 
                 (st_top == '{' && cur == '}') || 
                 (st_top == '[' && cur == ']') );
    }
};

/*
[{}()]
we can use a stack to record the string by order
becasue the stack is last in first out, this is the rule we need
when encountering a open char, we put it in.
when encountering a close char, we check if the top one can match.

*/