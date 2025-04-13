class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += i;
            ans -= nums[i];
        }
        ans += nums.size();
        return ans;
    }
};
/*
sum from 0 to n
for num in nums
    sum - num
the remaining is the answer
*/