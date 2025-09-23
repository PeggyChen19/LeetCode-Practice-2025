class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int lastValid = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[lastValid] != nums[i]) {
                lastValid++;
                swap(nums[lastValid], nums[i]);
            }
        }
        return lastValid + 1;
    }
};
/*
1 1 2
1 2 _

[valid array]
            ^ pointer to the end of valid array -> swap next valid value into here

if nums.empty() return 0
int lastValid = 0
for (int i = 1; i < n; i++) {
    if (nums[lastValid] != nums[i]) {
        lastValid++
        swap(lastValid, i)
    }
}
return swapInd
*/