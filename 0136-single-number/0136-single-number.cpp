class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int num : nums) {
            result ^= num;
        }
        return result;
    }
};
/*
1 2 2 1 3 -> find the single one: 3

XOR:
  0 1
0 0 1
1 1 0

A XOR A = 0
0 XOR A = A
0 ^ A ^ B ^ B ^ A ^ C = C
*/