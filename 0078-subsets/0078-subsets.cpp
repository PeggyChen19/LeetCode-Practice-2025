class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curSet;
        backtracking(0, nums, curSet, result);
        return result;
    }
private:
    void backtracking(int start, vector<int>& nums, vector<int>& curSet, vector<vector<int>>& result) {
        result.push_back(curSet);
        for (int i = start; i < nums.size(); i++) {
            curSet.push_back(nums[i]);
            backtracking(i+1, nums, curSet, result);
            curSet.pop_back();
        }
    }
};
/*
subset -> backtracking
for each element
1. choose it and go to next level 
2. not choose it and check next element (stay at the same level)
*/