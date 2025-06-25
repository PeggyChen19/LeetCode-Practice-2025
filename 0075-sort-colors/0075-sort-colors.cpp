class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, cur = 0, two = nums.size() - 1;
        while (cur <= two) {
            if (nums[cur] == 0) {
                swap(nums[cur], nums[zero]);
                zero++;
                cur++; // cur == 0 or 1 (not 2) -> safe -> skip it
            } else if (nums[cur] == 2) {
                swap(nums[cur], nums[two]);
                two--;
                // cur == 0 or 1 or 2 -> cannot skip -> handle it next round
            } else {
                cur++;
            }
        }
    }
};
/*
Two pointers: zero = 0, two = size - 1
iterate cur from zero
if i == 0 or 2 -> swap
else cur++
*/