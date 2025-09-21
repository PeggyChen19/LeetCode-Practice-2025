class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, cur = 0, two = nums.size() - 1;
        while (cur <= two) {
            if (nums[cur] == 0) {
                swap(nums[zero], nums[cur]);
                zero++;
                cur++;
            } else if (nums[cur] == 2) {
                swap(nums[two], nums[cur]);
                two--;
            } else {
                cur++;
            }
        }
    }
};
/*
3 parts: [0][1][2] -> use pointers to track the boundaries of the parts
0 0 0 x x x 1 1 x x 2 2 
      z           t
pointers, zero = 0 (the next position can fill with 0), two = n - 1, cur
use cur pointer to iterate the nums
cur = 0
while (cur <= two)
    if nums[cur] == 0
        swap(nums[zero], nums[cur])
        cur++ // zero must have 0 or 1, which is valid
        zero++
    elif nums[cur] == 2
        swap(nums[cur], nums[two])
        two--;
        // check cur next round
    else
        cur++
    
*/