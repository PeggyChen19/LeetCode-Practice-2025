class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2; // avoid overflow
            if (nums[mid] == target) {
                return mid;
            } else if (nums[left] <= nums[mid]) { // left side is sorted
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1; // go left
                } else {
                    left = mid + 1; // go right
                }
            } else { // right side is sorted
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1; // go right
                } else {
                    right = mid - 1; //go left
                }
            }
        }
        return -1;
    }
};

/*
binary search -> key will be "how to decide to go left or right"
set initial left, right index
while left <= right 
    mid = (left + right) / 2
    if mid == target
        return mid
    else if nums[left : mid] is sorted
        if left <= target < mid 
            go left
        else
            go right
    else
        if mid < target <= right
            go right
        else
            go left
return -1
*/