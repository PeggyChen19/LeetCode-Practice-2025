class Solution {
private:
    int partition(vector<int>& nums, int left, int right) {
        int start = left;
        int pivot = nums[start];
        while (left < right) { // end while when they are equal (no need to change)
            while (left < right && nums[right] <= pivot) right--;
            while (left < right && nums[left] >= pivot) left++;
            swap(nums[left], nums[right]);
        }
        swap(nums[start], nums[left]);
        return left;
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