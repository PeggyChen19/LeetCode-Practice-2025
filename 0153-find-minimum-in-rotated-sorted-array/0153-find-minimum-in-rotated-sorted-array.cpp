class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int lastVal = nums.back();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= lastVal) { // go left, try to find the smaller valid element
                right = mid - 1;
            } else { // go right
                left = mid + 1;
            }
        }
        return nums[left]; // left will stop at the first valid element
    }
};
/*
Every element is unique
Time: O(logn) -> binary search
| 1 2 3 4 5
  *
4 5 | 1 2 3
      *
2 3 4 5 | 1
          *
Find the first element <= the last element of the rotated array
*/