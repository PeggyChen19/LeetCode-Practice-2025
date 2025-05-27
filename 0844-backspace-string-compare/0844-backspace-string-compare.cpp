class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> sSt;
        stack<char> tSt;
        process(s, sSt);
        process(t, tSt);
        return sSt == tSt;
    }
private:
    void process(string str, stack<char>& st) {
        for (char& ch : str) {
            if (ch == '#' && !st.empty()) {
                st.pop();
            } else if (ch != '#'){
                st.push(ch);
            }
        }
    }
};
/*
Use stack: # means stack.pop() when not empty
*/