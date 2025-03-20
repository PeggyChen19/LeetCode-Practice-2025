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
    void backtracking(const vector<int>& candidates, int diff, int start) {
        if (diff == 0) {
            ans.push_back(combination);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            int new_diff = diff - candidates[i];
            if (new_diff >= 0) {
                combination.push_back(candidates[i]);
                backtracking(candidates, new_diff, i);
                combination.pop_back();
            }
        }
    }
};

/*
We need to check every possible combination -> enumeration + backtracking
-> use recursion to achieve it

void backtracking(diff, start):
    if diff == 0:
        add new result (combination)
        return
    for (int i = start; i < candidates.size(); i++):
        if diff - c >= 0:
            combination.push_back(c)
            backtracking(diff - c, i)
            combination.pop_back()
*/