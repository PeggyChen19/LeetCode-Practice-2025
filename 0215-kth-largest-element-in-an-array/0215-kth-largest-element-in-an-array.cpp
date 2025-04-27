class Solution {
private:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left], l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l++], nums[r--]);
            }
            if (nums[l] >= pivot) {
                l++;
            }
            if (nums[r] <= pivot) {
                r--;
            }
        }
        swap(nums[left], nums[r]);
        return r;
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        k--; // because index starts from 0
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int pivotInd = partition(nums, left, right);
            if (pivotInd == k) {
                return nums[pivotInd];
            }
            else if (pivotInd < k) {
                left = pivotInd + 1;
            }
            else {
                right = pivotInd - 1;
            }
        }
        return -1;
    }
};