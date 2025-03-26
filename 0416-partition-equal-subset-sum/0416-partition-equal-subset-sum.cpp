class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() == 0) {
            return false;
        }
        int half_sum = findHalfSum(nums);
        if (half_sum == -1) { // sum is odd number
            return false;
        }
        vector<bool> cur_sum(half_sum + 1, false); // include 0
        cur_sum[0] = true;
        if (nums[0] <= half_sum) {
            cur_sum[nums[0]] = true;
        } else {
            return false;
        }
        for (int i = 1; i < nums.size(); i++) { // start from 1 because 0 is initialized
            // do it backward to avoid overwriting original content
            for (int j = half_sum; j >= nums[i]; j--) { // prevent index to be negative -> j >= nums[i]
                cur_sum[j] = cur_sum[j - nums[i]] || cur_sum[j];
            }
        }
        return cur_sum[half_sum];
    }
private:
    int findHalfSum(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if ((sum % 2) == 0) {
            return sum / 2;
        } else { // odd number -> cannot be divided
            return -1;
        }
    }
};
/*
We want to choose some nums which sums to 1/2 sum(nums)
1. State & Subproblem
Sub-solution: if index 0~i can sum up to cur_sum or not 
State: index, cur_sum (0~1/2sum(nums))
2. Decision
Choose it or not
3. State Transition Function
dp(i, sum) = dp(i-1, sum - nums[i]) || dp(i-1, sum)
              ^ choose                  ^ not choose
4. Base Case
dp(0, nums[0]) = true
dp(0, 0) = true
5. Computational Sequence (bottom-up / top-down)
bottom-up: use double for loop to go through all nums & all sum
6. Memorization - build a lookup table
build an 1D vector to record sum 0~1/2sum(nums)
we don't need to record every i because we can only record the last one only
*/