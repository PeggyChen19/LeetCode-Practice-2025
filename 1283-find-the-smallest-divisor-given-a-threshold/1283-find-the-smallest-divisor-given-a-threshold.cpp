class Solution {
public:
    bool validDivisor(vector<int>& nums, int divisor, int threshold) {
        int sum = 0;
        for (int& num : nums) {
            if (num % divisor == 0)
                sum += num / divisor;
            else
                sum += num / divisor + 1;
            if (sum > threshold)
                return false;
        }
        return true;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = 0;
        for (int& num : nums) {
            right = max(right, num);
        }
        while (right >= left) {
            int mid = left + (right - left) / 2; // avoid overflow
            if (validDivisor(nums, mid, threshold))
                right = mid - 1;
            else
                left = mid + 1;
        }

        return left;
    }
}
;
