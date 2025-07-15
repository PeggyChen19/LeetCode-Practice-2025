class Solution {
public:
    int lengthOfLongestSubstring(string s) {    
        int globalMax = 0, left = 0;
        unordered_set<char> window;
        for (int right = 0; right < s.size(); right++) {
            char newChar = s[right];
            while (window.count(newChar)) { // shrink until no newChar in current window
                window.erase(s[left]);
                left++;
            }            
            window.insert(newChar); // insert new char
            globalMax = max(globalMax, right - left + 1);
        }
        return globalMax;
    }
};
/*
Slding window
use globalMax to track the result
use unordered_set to check duplicate
while not reach end
    expand right until duplicated
    shrink left until not duplicated
*/