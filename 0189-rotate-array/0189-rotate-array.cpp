class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // in-place solution
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
/*
Common Step: k = k % nums.size()

Solution 1: Brute-force
Create extra vector
newInd = (curInd + k) % nums.size()
T: O(n), S: O(n)

Solution 2: In-place
n-k |   k
1 2 | 3 4 5, k = 3
3 4 5 | 1 2
We actually need to swap 2 subarrays
How to do it in-place? swap(A+B), swap(A), swap(B)
T: O(n), S: O(1)

Solution 3: deque
T: O(k+n), S: O(n)
*/