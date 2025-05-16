class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curSet;
        sort(nums.begin(), nums.end());
        backtracking(0, nums, curSet, result);
        return result;
    }
private:
    void backtracking(int start, vector<int>& nums, vector<int>& curSet, vector<vector<int>>& result) {
        result.push_back(curSet);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i-1]) {
                continue;
            }
            curSet.push_back(nums[i]);
            backtracking(i+1, nums, curSet, result);
            curSet.pop_back();
        }
    }
};
/*
nums = [1,2,2]
[[],[1],[1,2],[1,2,2],[2],[2,2]]
All possible subsets and remove duplicates
Sort to gather duplicate vals
backtracking
For each num, choose it or not and go to next level
For the duplicated values in the same round -> only choose the first one
*/