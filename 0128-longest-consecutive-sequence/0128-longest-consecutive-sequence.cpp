class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0; // Explicit check for empty input
        int ans = 0;
        unordered_set<int> numsSet(nums.begin(), nums.end());
        for (int num : numsSet) { // go through numsSet to avoid duplicate operations
            if (!numsSet.count(num - 1)) { // starting point
                int len = 1;
                int next = num + 1;
                while(numsSet.count(next)) {
                    len++;
                    next++;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};

/*
go through nums
    store each num in unordered_set
go through nums
    check if nums[i] - 1 exists
    if yes -> pass, this is not the starting point
    if no -> increase the value one by one and then check if that value exists
        record the longest length
T: O(n)
S: O(n)
*/