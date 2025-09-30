class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k--; // this is the 0-indexed
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int pivot = quickSelect(nums, left, right);
            if (pivot == k) {
                return nums[pivot];
            } else if (pivot < k) { // go right
                left = pivot + 1;
            } else { // go left
                right = pivot - 1;
            }
        }
        return 0; // not found -> impossible
    }
private:
    int quickSelect(vector<int>& nums, int left, int right) {
        // target: left part >= pivot, right part <= pivot
        int pivot = nums[left], l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) { // both invalid -> swap
                swap(nums[l], nums[r]);
                l++;
                r--;
            } 
            if (l <= r && nums[l] >= pivot) { // valid, move forward
                l++;
            }
            if (l <= r && nums[r] <= pivot) { // valid, move backward
                r--;
            }
        }
        // after loop, it ends up [left... r l ...]
        // r >= pivot, so swap to the left side
        swap(nums[r], nums[left]);
        return r;
    }
};