class Solution {
public:
    long long calActionNeed(long long sum, vector<int>& nums, int left, int right) {
        return (long long)nums[right] * (right - left + 1) - sum;
    }

    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        int result = 0;
        long long sum = 0;
        sort(nums.begin(), nums.end());
        while (right < n) {
            sum += nums[right];
            long long actionNeed = calActionNeed(sum, nums, left, right);
            while (actionNeed > k) {
                sum -= nums[left];
                left++;
                actionNeed = calActionNeed(sum, nums, left, right);
            }

            result = max(result, right - left + 1);
            right++;
        }
        return result;
    }
};