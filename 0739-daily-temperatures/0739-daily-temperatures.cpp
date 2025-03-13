class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<pair<int, int>> st; // value, index
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first <= temperatures[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top().second - i;
            }
            st.push({temperatures[i], i});
        }
        return ans;
    }
};

/*
we would like to find "the first higher value" on the right
we can have a stack to record an strict decreasing order from bottom to top, and
we will build this stack from right to left
if we iterate to a new value
    1. pop the top it until meeting a bigger one or reaching the end
    2. find the ans and then push the new value into stack
We need to know the both value & index -> record both in stack
T: O(n), S: O(n)
*/