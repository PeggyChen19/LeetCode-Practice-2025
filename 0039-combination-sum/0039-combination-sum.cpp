class Solution {
private:
    vector<vector<int>> ans;
    vector<int> combination;

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0);
        return ans;
    }

private:
    void backtracking(const vector<int>& candidates, int remaining, int start) {
        if (remaining == 0) {
            ans.push_back(combination);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] <= remaining) {
                combination.push_back(candidates[i]);
                backtracking(candidates, remaining - candidates[i], i);
                combination.pop_back();
            }
        }
    }
};

/*
We need to check every possible combination -> enumeration + backtracking
-> use recursion to achieve it

function backtracking(remaining, start):
    if remaining == 0:
        add combination to result
        return
    for (int i = start; i < candidates.size(); i++):
        if remaining >= c:
            combination.push(c)
            backtracking(remaining - c, i)
            combination.pop()
*/