class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int globalMax = 0;
        int left = 0;
        unordered_set<char> window;
        for (int right = 0; right < s.size(); right++) {
            while (window.count(s[right])) { // remove duplication and move window forward
                window.erase(s[left]);
                left++;
            }
            window.insert(s[right]); // insert new element into window
            globalMax = max(globalMax, right - left + 1);
        }
        return globalMax;
    }
};