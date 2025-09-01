class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = 0; // size of the new valid array
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                swap(nums[i], nums[size]);
                size++;
            }
        }
        return size;
    }
};

/*
in-place: swap
two pointers: 
1. iterate the array one by one
2. point to the end of the valid array (the size of valid array)

valid = 0
for each int:
	if int != val:
		swap(int, valid);
	    valid++;
return valid
*/