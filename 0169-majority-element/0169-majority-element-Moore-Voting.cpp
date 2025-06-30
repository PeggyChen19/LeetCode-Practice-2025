class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (count == 0) {
                candidate = nums[i];
            }
            count += (nums[i] == candidate) ? 1 : -1;
        }
        return candidate;
    }
};
/*
Moore Voting Algorithm
The majority appears more than all other nums
use int candidate to record the current possible result
use int count: increase (meet candidate) or decrease (not meet candidate)
when count == 0 -> change candidate
*/