class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numsMap;
        for (int i = 0; i <= nums.size(); i++) {
                int seeking = target - nums[i];
                if (numsMap.count(seeking)) {
                    return {i, numsMap[seeking]};
                }
                numsMap[nums[i]] = i;
        }
        return {-1, -1};
    }
};

