class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int size = 1, prev = nums[0];
        bool twice = false;
        for (int i = 1; i < nums.size(); i++) {
            if (prev == nums[i]) { // duplicate
                if (!twice) { // valid
                    twice = true;
                    swap(nums[size], nums[i]);
                    size++;
                }
            } else { // update prev
                prev = nums[i];
                twice = false;
                swap(nums[size], nums[i]);
                size++;
            }
        }
        return size;
    }
};
/*
Target: keep at most two the same elements
Method: 
1. keep one pointer (int) points to the next element of the end of valid list
2. when there are more than two elements -> points to the redundant and wait for swapping with the next valid element 
*/