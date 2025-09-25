class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int p1 = 0, p2 = 0;
        vector<int> result;
        while (p1 < nums1.size() && p2 < nums2.size()) {
            if (p1 < nums1.size() && nums1[p1] < nums2[p2]) p1++;
            else if (p2 < nums2.size() && nums2[p2] < nums1[p1]) p2++;
            else {
                result.push_back(nums1[p1]);
                do {p1++;} while (p1 < nums1.size() && nums1[p1 - 1] == nums1[p1]);
                do {p2++;} while (p2 < nums2.size() && nums2[p2 - 1] == nums2[p2]);
            }
        }
        return result;
    }
};
/*
method 1: sort + two pointers
sort nums1 & nums2, compare(ignore duplications)
while (p1 < size1 && p2 < size2)
    if (p1 < p2) p1++
    elif (p2 < p1) p2++
    else // p1 == p2
        push into result
        do p1++ while (p1 == previous p1)
        do p2++ while (p2 == previous p2)

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