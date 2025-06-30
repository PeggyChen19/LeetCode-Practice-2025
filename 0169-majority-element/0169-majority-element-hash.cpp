class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int& num : nums) {
            freq[num]++;
            if (freq[num] > n / 2) return num;
        }
        return -1;
    }
};
/*
Method 1:
Go through the nums and record the frequency (unordered_map)
Time: O(n)
Space: O(n)

Method 2:
Sort the nums, the nums at (n/2) is the answer
Time: O(nlogn)
Space: O(1)
*/