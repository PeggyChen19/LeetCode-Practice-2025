class Solution {
private:
    vector<vector<int>> results;
    void backtracking(vector<int>& vec, int start, int remain, vector<int>& candidates) {
        if (remain == 0) {
            results.push_back(vec);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i-1]) {
                continue; // avoid duplicate val in the same level
            }
            int new_remain = remain - candidates[i];
            if (new_remain >= 0) {
                vec.push_back(candidates[i]);
                backtracking(vec, i+1, new_remain, candidates);
                vec.pop_back();
            } else {
                break;
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> vec;
        backtracking(vec, 0, target, candidates);
        return results;
    }
};
/*
Backtracking:
for each candiate[i] from the starting point
    if i and i+1 are on the same level and candidates[i] == candidates[i+1]
        continue
    choose i
    do the recursion -> set the starting point as i+1
    backtrack (undo the choice)
*/