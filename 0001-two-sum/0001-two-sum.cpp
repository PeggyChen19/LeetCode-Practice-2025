class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> search;
        for (int i = 0; i <= nums.size(); i++) {
                int seeking = target - nums[i];
                if (search.count(seeking)) {
                    return vector({i, search[seeking]});
                }
                search[nums[i]] = i;
        }
        return {-1, -1};
    }
};

