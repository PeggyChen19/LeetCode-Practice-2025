class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curPath;
        helper(candidates, 0, target, result, curPath);
        return result;
    }
private:
    void helper(vector<int>& candidates, int start, int remain, vector<vector<int>>& result, vector<int>& curPath) {
        if (remain < 0) return;
        if (remain == 0) {
            result.push_back(curPath);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            curPath.push_back(candidates[i]);
            helper(candidates, i, remain - candidates[i], result, curPath);
            curPath.pop_back();
        }
    }
};
/*
find all possible combinations -> backtracking
candidate is distinct, can choose candidate more than once
helper(start)
    for i = start; i < candidiates.size(); i++
        choose candidates[i]
        helper(i)
        unchoose candidates[i]
*/