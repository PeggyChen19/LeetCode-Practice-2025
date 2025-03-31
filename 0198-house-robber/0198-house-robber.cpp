class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) { // edge case
            return 0;
        }
        int back_two = 0;
        int back_one = 0;
        for (int i = 0; i < nums.size(); i++) {
            int new_back_two = back_one;
            back_one = max(nums[i] + back_two, back_one);
            back_two = new_back_two;
        }
        return back_one;
    }
};
/*
1 3 5 1 1 5 1 3
1+5+5+3=14
The best ans won't be only odd index or only even index
We need to divide the problem
State: index
Subsolution: the current max money
Decision:
1. Choose the cur one + the max money of (cur-2)
2. Not Choose the cur one + the max money of (cur-1)
Transition function:
f(i) = max(nums[i] + f(i-2), f(i-1))
Base case:
f(-1) = 0, f(0) = nums[i]
Computational Sequence:
use a for loop to update
Memorization:
We can only remember two variables -> i-1 & i-2 
*/