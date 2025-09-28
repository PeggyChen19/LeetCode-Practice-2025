
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = (int)nums.size();
        if (n <= 1) return;

        vector<int> a(nums);
        sort(a.begin(), a.end());

        int mid = n / 2 + n % 2; // mid is the start of large half
        int i = mid - 1;        // last index of small half (descending)
        int j = n - 1;          // last index of large half (descending)

        for (int k = 0; k < n; ++k) {
            if (k % 2 == 0) nums[k] = a[i--];  // even: smaller (desc)
            else            nums[k] = a[j--];  // odd : larger  (desc)
        }
    }
};