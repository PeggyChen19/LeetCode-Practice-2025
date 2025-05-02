class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            ans ^= nums[i];
        }
        return ans;
    }
};
/*
A xor A = 0
0 xor B = B
There are several pairs and only one single -> XOR all nums and the result is the ans
*/