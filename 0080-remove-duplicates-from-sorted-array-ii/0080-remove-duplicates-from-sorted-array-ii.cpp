class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (size < 2 || nums[size - 2] != nums[i]) {
                nums[size] = nums[i];
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
2. when there are more than two elements -> wait for swapping with the next valid element 
*/