class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        for (int i = 0; i < n; i++) {
            while (nums[i] != nums[nums[i] - 1]) { // for each nums[i], it has the correct index nums[i] - 1
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) result.push_back(i + 1);
        }
        return result;
    }
};
/*
key: value range [1 ~ n], index range [0 ~ n - 1]
for each val, try to put it to the correct index
*/