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
iterate cur from zero to two
if i == 0
    swap; zero++; i++;
else if i == 2
    swap; two--;
else
    cur++;
Dutch National Flag Algorithm
只有從 right 換進來的數值要再檢查一次，從 left 換來的值是安全的
*/