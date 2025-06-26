class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n =  nums.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid == n - 1 || nums[mid] > nums[mid + 1]) { // go left
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left; // the first element which nums[mid] > nums[mid+1] -> peak
    }
};
/*
time: O(logn)
binary search
for a peak: (up: up, d: down)
u u * d d d u u u * d d d
if (nums[i] > nums[i+1]) down -> go left
else up -> go right
*/