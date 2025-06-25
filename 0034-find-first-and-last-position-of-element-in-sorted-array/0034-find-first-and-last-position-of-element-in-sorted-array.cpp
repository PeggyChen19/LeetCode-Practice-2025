class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size() - 1;
        int first = binarySearch(nums, 0, size, target, true); // the first element >= target
        if (first > size || nums[first] != target) { // cannot find target
            return {-1, -1};
        }
        int last = binarySearch(nums, first, size, target, false); // the first element > target
        last--;
        return {first, last};
    }
private:
    int binarySearch(vector<int>& nums, int left, int right, int target, bool equal) {
        int mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if ((equal && nums[mid] >= target) || (!equal && nums[mid] > target)) { // go left, try to find eariler valid one
                right = mid - 1;
            } else { // go right
                left = mid + 1;
            }
        }
        return left; // left is the first index satisfies the condition
    }
};
/*
1 2 3 3 4 5, 3
Find the index range of target -> Binary search O(logn)
Do the binary search twice
1. Find the first element >= target
2. Find the first element > target
*/