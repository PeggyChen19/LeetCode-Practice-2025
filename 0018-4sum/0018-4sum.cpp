class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i <= n - 4; i++) {
            if (i != 0 && nums[i - 1] == nums[i]) continue;
            for (int j = i + 1; j <= n - 3; j++) {
                if (j != i + 1 && nums[j - 1] == nums[j]) continue;
                long long remain = (long long) target - nums[i] - nums[j];
                int l = j + 1, r = n - 1;
                while (l < r) {
                    long long twoSum = (long long) nums[l] + nums[r];
                    if (twoSum == remain) {
                        result.push_back({nums[i], nums[j], nums[l], nums[r]});
                        do {l++;} while (l < r && nums[l - 1] == nums[l]);
                        do {r--;} while (l < r && nums[r + 1] == nums[r]);
                    } else if (twoSum > remain) {
                        do {r--;} while (l < r && nums[r + 1] == nums[r]);
                    } else {
                        do {l++;} while (l < r && nums[l - 1] == nums[l]);
                    }
                }
            }
        }
        return result;
    }
};
/*
2 sum: unordered_map O(n)
3 sum: sort + two pointers O(n^2)
4 sum: sort + double loop + two pointers O(n^3)
*/