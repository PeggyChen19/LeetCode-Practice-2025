class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }
        int start = 0, len = 0;
        for (int i = 0; i < s.size(); i++) {
            expandPalindrome(s, i, i, start, len);
            expandPalindrome(s, i, i+1, start, len);
        }
        return s.substr(start, len);
    }
private:
    void expandPalindrome(string s, int left, int right, int& start, int& len) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        if (right - left - 1 > len) { // (right - 1) - (left + 1) + 1
            start = left + 1;
            len = right - left - 1;
        }
    }
};
/*
for palindromic, we need to find the center and then expand it until invalid
for char in s
    choose char as center
    expand()
    choose char & char+1 as center
    expand()

func expand()
    while palindrome is valid
        expand the substring
*/