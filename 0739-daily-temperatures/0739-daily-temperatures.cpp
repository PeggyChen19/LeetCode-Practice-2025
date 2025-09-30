class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> decreasingSt;
        for (int i = n - 1; i >= 0; i--) {
            while (!decreasingSt.empty() && temperatures[decreasingSt.top()] <= temperatures[i]) {
                decreasingSt.pop();
            }
            if (!decreasingSt.empty()) result[i] = decreasingSt.top() - i;
            decreasingSt.push(i);
        }
        return result;
    }
};
/*
find the next strickly greater element on the right side
monotonic decreasing stack (top is the smallest, if it's smaller than current, pop, find the first elemnt > cur)
build the stack from right to left (always maintain the valid right candidates)

stack can store the index only, and then we use index to lookup value
*/