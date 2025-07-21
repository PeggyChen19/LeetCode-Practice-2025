class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numsSet;
        for (int& num : nums) {
            numsSet.insert(num);
        }
        int maxLen = 0;
        for (auto& num : numsSet) { // iterate set to avoid duplications
            if (!numsSet.count(num - 1)) { // the start point
                int len = 0, cur = num;
                while (numsSet.count(cur)) {
                    cur++;
                    len++;
                }
                maxLen = max(len, maxLen);
            }
        }
        return maxLen;
    }
};
/*
Time limit: O(n)
disjoint set? -> hard to track the consecutive intervals' start & end
need to find the element's neighbors in O(1) -> hash map
Solution:
1. store all nums into unorderd_set
2. go through all nums, check if it's the start of the consecutive sequence via unordered_set
3. if it's the start point, build the sequence
4. return the max sequence
*/