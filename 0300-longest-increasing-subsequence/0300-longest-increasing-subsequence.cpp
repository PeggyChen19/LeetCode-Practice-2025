class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int seq_end = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[seq_end]) { // append nums[i] to seq
                seq_end++;
                nums[seq_end] = nums[i];
            } else if (nums[i] < nums[seq_end]){ // replace the min seq element which is bigger than nums[i]
                binarySearch(nums, 0, seq_end, nums[i]);
            }
            // if nums[i] == nums[seq_end] -> ignore
        }
        return seq_end + 1;
    }
private:
    void binarySearch(vector<int>&nums, int left, int right, int target) {
        while (left <= right) {
            int mid = left + ((right - left) / 2);
            if (nums[mid] == target) { // no need to replace
                return;
            } else if (nums[mid] > target) { // go left
                right = mid - 1;
            } else if (nums[mid] < target) { // go right
                left = mid + 1;
            }
        }
        nums[left] = target; // we want to repalce (sth > target) to target
    }
};
/*
2 7 8 4 9 1 3
We might have multiple possible subsequences
2 7 8 9
2 4   9
1 3
真正的 LIS 是什麼我們並不在意，我們需要的是維護一個 seq，裡面元素越小越好，有利於後面新元素的擴展
1. 當遇到新元素比末端大 -> 直接新增入 array
2. 當遇到新元素比末端小 -> 取代掉「大於」該元素的「最小值」，當更新到末端時，就可以增加未來擴展的潛力
   -> 用 binray search 去到找到這個目標
Binary Search:
target=4
1  3  5  7
      lr
1  3  5  7
  lr
*/