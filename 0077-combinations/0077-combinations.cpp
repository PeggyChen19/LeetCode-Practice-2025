class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        vector<vector<int>> result;
        helper(1, n, k, cur, result);
        return result;
    }
private:
    void helper(int start, int n, int k, vector<int>& cur, vector<vector<int>>& result) {
        if (cur.size() == k) {
            result.push_back(cur);
            return;
        }
        for (int i = start; i <= n; i++) {
            cur.push_back(i);
            helper(i + 1, n, k, cur, result);
            cur.pop_back();
        }
    }
};
/*
[1, 2] and [2, 1] are considered the same
backtracking -> recursive
choose i from start to n
recursion(start = i + 1, end = n)
unchoose i
*/