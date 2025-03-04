class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numsSet;
        for (int i = 0; i < nums.size(); i++) {
            if (numsSet.count(nums[i])) {
                return true;
            }
            numsSet.insert(nums[i]);
        }
        return false;
    }
};

/*
unordered_set set
loop for all nums {
    if set.count(nums[i]) {
        return true
    }
    set.insert(nums[i])
}
return false

time: O(n)
space: O(n)
*/