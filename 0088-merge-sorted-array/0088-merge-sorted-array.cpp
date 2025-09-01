class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int iter1 = m - 1, iter2 = n - 1;
        for (int i = m + n - 1; i >= 0; i--) {
            if (iter2 < 0) return;
            else if (iter1 >= 0 && nums1[iter1] > nums2[iter2]) {
                nums1[i] = nums1[iter1];
                iter1--;
            } else {
                nums1[i] = nums2[iter2];
                iter2--;
            }
        }
    }
};
/*
bulid the array from big to small (from right to left)
three pointers: new array, nums1, nums2
*/