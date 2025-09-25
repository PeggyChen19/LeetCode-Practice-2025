class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.size() < nums1.size()) {
            swap(nums1, nums2);
        }
        unordered_set<int> s1(nums1.begin(), nums1.end());
        vector<int> result;
        for (int num : nums2) {
            if (s1.count(num)) {
                result.push_back(num);
                s1.erase(num);
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
Time: O(n + m)
Space: O(min(n, m))
*/