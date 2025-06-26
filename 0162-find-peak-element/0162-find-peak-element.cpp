class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n =  nums.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if ((mid == 0 || nums[mid] > nums[mid - 1]) && (mid == n - 1 || nums[mid] > nums[mid + 1])) {
                return mid; // peak
            } else if (mid == 0 || nums[mid - 1] < nums[mid]) { // go right
                left = mid + 1;
            } else { // go left
                right = mid - 1;
            }
        }
        return -1;
    }
};
/*
time: O(logn)
binary search
for a peak: (up: up, d: down)
u u * d d d u u u * d d d
if (nums[i] > nums[i-1] && nums[i] > nums[i + 1]) return peak
else if (nums[i - 1] < nums[i]) up -> go right
else if (nums[i - 1] > nums[i]) down -> go left
*/