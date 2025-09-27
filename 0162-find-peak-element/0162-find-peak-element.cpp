class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if ( (mid == 0 || nums[mid - 1] < nums[mid]) && (mid == n - 1 || nums[mid] > nums[mid + 1]) { // peak
                return mid;
            } else if (mid == 0 || nums[mid - 1] < nums[mid]) { // increasing -> go right
                left = mid + 1;
            } else { // decreasing -> go left
                right = mid - 1;
            }
        }
        return -1;
    }
};
/*
Time limit: O(logn) -> shrink the search range based on some condition -> binary search
set nums[-1] = nums[n] = -infinite
for each round, find mid, mid - 1, mid + 1
if mid is peak
    return mid
elif mid is in increasing order
    find peak from right part
else
    find peak from left part
*/