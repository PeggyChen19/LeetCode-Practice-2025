class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k == 0) return false;
        int start = 0;
        unordered_set<int> window;
        for (int num : nums) {
            if (window.count(num)) return true;
            if (window.size() == k) {
                window.erase(nums[start]);
                start++;
            }
            window.insert(num);
        }
        return false;
    }
};
/*
0 1 2 3 4
i       j, j - i = 4
k = 3 -> false
k = 4 -> true
k = 5 -> true

unordered_set<int> // current nums in window k
use an pointer to the start of the window
iterate the whole array
*/