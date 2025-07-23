class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        stack<int> st;
        vector<int> result(size, 0);
        for (int i = 0; i < size; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                result[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};
/*
Target: find the "first" element bigger than the current one on the right side
We can maintain a monotonic stack which is decreasing -> the elements in the stack haven't found the bigger one
When find the bigger one, pop the smaller elements and maintain the stack
Note: record the stack using index
*/