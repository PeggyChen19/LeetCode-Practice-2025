class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> content;
        int maxLen = 0, slow = 0;
        for (int fast = 0; fast < s.size(); fast++) {
            while (content.count(s[fast])) {
                content.erase(s[slow]);
                slow++;
            } 
            content.insert(s[fast]);
            maxLen = max(maxLen, fast - slow + 1);
        }
        return maxLen;
    }
};

/*
substring -> sliding window
fast: go through the string one by one
slow: go right when the current window has duplicate values
use unordered_set to record window content
update maxLen
*/