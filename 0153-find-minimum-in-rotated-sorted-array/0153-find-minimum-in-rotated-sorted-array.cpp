class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int lastValue = nums[right];
        while (left <= right) {
            int mid = left + (right - left) / 2; // avoid overflow
            if (nums[mid] <= lastValue) { // mid is in the right group -> go left
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return nums[left];
    }
};

/*
The sorted array 經過未知次數 rotate，要找到 min value of this array
Time complexity: O(logn)
min array length? 1
unique? yes
input: 6  7  1  2  3  4  5
output: 1
input: 1
output: 1
input: 1  2  3  4  5
output: 1

increasing(bigger) drop increasing
binary search -> divide the array into 2 groups
left: > the last element
right: <= the last element
our target will be the first one in right group
*/