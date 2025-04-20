class Solution {
private:
    vector<vector<int>> results;
    void sub_permute(int start, vector<int>& nums) {
        if (start == nums.size() - 1) { // last element
            results.push_back(nums);
        }
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            sub_permute(start+1, nums);
            swap(nums[start], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sub_permute(0, nums);
        return results;
    }
};
/*
123
123 132 213 231 321 312

func permute(start)
    if i is end
        ans.push
    for (i = start; i < size; i++)
        swap(start, i)
        permute(start+1)
        swap(start, i)
*/