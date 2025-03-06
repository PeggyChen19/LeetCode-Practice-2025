class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> numsSet;
        for (int num : nums) {
            numsSet.insert(num);
        } 
        for (int num : nums) {
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