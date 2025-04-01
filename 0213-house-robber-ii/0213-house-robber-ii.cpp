class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }
        return max(sub_rob(nums, 0, size - 2), sub_rob(nums, 1, size -1));
    }
private:
    int sub_rob(vector<int>& nums, int start, int end) {
        int prev_two = 0, prev_one = 0;
        for (int i = start; i <= end; i++) {
            int cur = max(prev_one, prev_two + nums[i]);
            prev_two = prev_one;
            prev_one = cur;
        }
        return prev_one;
    }
};
/*
State: index
Sub-solution: the max money from index 0~i
Decision: Rob current one or not
Transition function:
f(i) = max(f(i-1), f(i-2) + nums[i])
Base case:
f(-1) = 0
f(0) = nums[0] OR 0
Implementation: 
use 2 separate for loop:
1. choose the first one (f(0) = nums[0]) and not choose the last one (end the loop earlier)
-> loop from 0 to n-2
2. not choose the first one (f(0) = 0) and choose the last one based on function
-> loop from 1 to n-1
Memorization:
Use two variables: prev_one & prev_two
*/