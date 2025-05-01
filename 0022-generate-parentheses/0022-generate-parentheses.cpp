class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> results;
        string ans = "(";
        backtracking(1, n-1, ans, results);
        return results;
    }
private:
    void backtracking(int unmatched, int unused, string& ans, vector<string>& results) {
        if (unmatched == 0 && unused == 0) {
            results.push_back(ans);
        }
        if (unmatched > 0) {
            ans.push_back(')');
            backtracking(unmatched-1, unused, ans, results);
            ans.pop_back();
        }
        if (unused > 0) {
            ans.push_back('(');
            backtracking(unmatched+1, unused-1, ans, results);
            ans.pop_back();
        }
    }
};
/*
use backtracking to span all possibilities
for each round, we can choose
1. put left (if there is unused left)
2. put right to match existing left
we need to record the number of
1. unused left
2. unmatched left
3. matched left (= all-1-2)

backtracking("(", 1, n-1)
void backtracking(string& ans, int unmatched, int unused)
    if(unmatched == 0 && unused == 0)
        results.push(ans)
    if(unmatched > 0)
        ans.push(")")
        backtracking(ans, unmatched-1, unused)
        ans.pop
    if(unused > 0)
        ans.push("(")
        backtracking(ans, unmatched+1, unused-1);

*/