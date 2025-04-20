class Solution {
private:
    vector<vector<int>> results;
    void backtracking(vector<int>& vec, int start, int remain, vector<int>& candidates) {
        if (remain == 0) {
            results.push_back(vec);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i-1]) { // avoid duplicate val in the same level
                continue;
            }
            int new_remain = remain - candidates[i];
            if (new_remain >= 0) {
                vec.push_back(candidates[i]);
                backtracking(vec, i+1, new_remain, candidates);
                vec.pop_back();
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
1 2 3 1 -> 5
1 1 3
2 3
function backtracking(vector<int>, ind, sum)
    if sum == target
        results.push_back()
    if sum + candidate[i] <= target
        vec.push_back(candidate[i])
        backtracking(vec, i+1, sum+candidate[i])
        vec.pop_back()
    backtracking(vec, i+1, sum)
*/