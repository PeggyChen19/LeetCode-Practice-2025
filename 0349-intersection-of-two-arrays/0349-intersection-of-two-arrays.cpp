class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int p1 = 0, p2 = 0, n = nums1.size(), m = nums2.size();
        vector<int> result;
        while (p1 < n && p2 < m) {
            if (nums1[p1] < nums2[p2]) p1++;
            else if (nums2[p2] < nums1[p1]) p2++;
            else {
                result.push_back(nums1[p1]);
                while (p1 < n && nums1[p1] == result.back()) p1++;
                while (p2 < m && nums2[p2] == result.back()) p2++;
            }
        }
        return result;
    }
};
/*
method 1: sort + two pointers
sort nums1 & nums2, compare(ignore duplications)
Time: O(nlogn + mlogm)
Space: O(1)

method 2: hash table
if (nums2.size < nums1.size)
    swap(nums1, nums2)
store nums1 into unordered_set<int>
iterate nums2
    if (nums2[i] in unordered_set)
        push into result
        erase nums2[i] from unordered_set
Time: O(max(n, m))
Space: O(min(n, m))
*/