class Solution {
private:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left], l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
            if (nums[l] >= pivot) l++;
            if (nums[r] <= pivot) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        k--;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int ind = partition(nums, left, right);
            if (ind == k) return nums[ind];
            else if (ind > k) right = ind - 1; // go left
            else left = ind + 1; // go right
        }
        return -1;
    }
};
/*
Quick Select:
partision:
    select a pivot, place nums < pivot to left, >= pivot to right
recursively do the partision based on the index of pivot until index == k
*/