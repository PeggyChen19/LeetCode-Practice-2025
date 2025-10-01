class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) return findMedianSortedArrays(nums2, nums1); // always binary search the smaller part
        int leftPart = (m + n) / 2;
        int left = 0; // put everything to right
        int right = m; // put everythin to left
        while (left <= right) {
            int i = left + (right - left) / 2;
            int j = leftPart - i;
            // if left part of nums1 is empty, cannot be chosen as max -> set as INT_MIN
            int left_max_one = (i == 0) ? INT_MIN : nums1[i - 1];
            int left_max_two = (j == 0) ? INT_MIN : nums2[j - 1];
            int right_min_one = (i == m) ? INT_MAX : nums1[i];
            int right_min_two = (j == n) ? INT_MAX : nums2[j];
            if (left_max_one <= right_min_two && left_max_two <= right_min_one) { // valid cuts
                int left_max = max(left_max_one, left_max_two);
                int right_min = min(right_min_one, right_min_two);
                if ((m + n) % 2) { // odd
                    return right_min;
                } else {
                    return (double) (left_max + right_min) / 2;
                }
            } else if (left_max_one > right_min_two){ // i go left
                right = i - 1;
            } else { // i go right
                left = i + 1;
            }
        }
        return 0.0;
    }
};
/*
for the merged sorted vector, we want to find a cut to evenly separate left & right
we will have two cuts to cut nums1 & nums2
nums1.left(i elements) + nums2.left (j element) = merged.left (m + n / 2)
// right side has one more when total is odd

if nums1[i - 1] <= nums2[j] && nums2[j - 1] <= nums1[i]
    the two cuts are valid
    return median
else if nums1[i - 1] > nums2[j]
    move i to left
else
    move i to right
*/