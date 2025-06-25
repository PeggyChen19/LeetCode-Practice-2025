class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int once = 0, twice = 0;
        for (int& num : nums) {
            once = (once ^ num) & ~twice; // exclude those bits appear twice
            twice = (twice ^ num) & ~once; // exclude those bits appear once
        }
        return once;
    }
};
/*
1 num: appears once, other nums: appears 3 times 
Time: O(n), Space: (1)

Bit manipulation (XOR)? not work, we can't tell the difference between 1 or 3 times
Sum up nums and mod 3? not work, for nums which can divide by 3 itself, we can't filter out it
-> track how many times each bit has appeared, and then mod 3 
How? use two integers: once and twice to record bit states
*/