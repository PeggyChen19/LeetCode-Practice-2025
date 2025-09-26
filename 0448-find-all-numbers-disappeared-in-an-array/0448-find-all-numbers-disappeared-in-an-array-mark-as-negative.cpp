class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        for (int i = 0; i < n; i++) {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0) continue;
            else nums[index] = -nums[index];
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) result.push_back(i + 1);
        }
        return result;
    }
};
/*
key: value range [1 ~ n], index range [0 ~ n - 1]
we can somehow mark the values existing or not by using index

for i = 0; i < size; i++
    let nums[abs(nums[i]) - 1] be negative, which means that this value exist
for i = 0; i < sizz; i++
    if nums[i] is positive -> push into result
*/