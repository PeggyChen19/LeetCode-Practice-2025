class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;
        for (int i = n - 1; i > 0; i--) {
            if (nums[i - 1] < nums[i]) {
                pivot = i;
                break;         
            }
        }
        if (pivot == -1) { // the last permutation (strictly decreasing)
            reverse(nums.begin(), nums.end());
            return;
        }
        int left = pivot - 1;
        for (int i = n - 1; i > left; i--) {
            if (nums[i] > nums[left]) {
                swap(nums[i], nums[left]);
                break;
            }
        }
        reverse(nums.begin() + pivot, nums.end());
        return;
    }
};
/*
Normal case: do the "min change" to make the permutation bigger
min change -> try to find the rightmost possible change
for decreasing part (from left to right), can't make bigger
-> find the first element (pivot), which is bigger than its left neighbor (left)
swap(left, the first and rightmost element which is bigger than left)
reverse(right, end)

Special case: the last permutation -> reverse the nums

Normal example
1 2 4 3 5
      l p/b
1 2 4 5 3

1 5 4 3 2
l p     b
2 5 4 3 1
  [reverse]
2 1 3 4 5

2 5 4 3 1
l p   b
3 5 4 2 1
  [reverse]
3 1 2 4 5
*/