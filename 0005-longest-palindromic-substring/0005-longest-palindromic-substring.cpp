class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            ans = expandPalindrome(s, i-1, i+1, string(1, s[i]), ans);
            ans = expandPalindrome(s, i, i+1, "", ans);
        }
        return ans;
    }
private:
    string expandPalindrome(string s, int left, int right, string local_ans, string ans) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            local_ans = s[left] + local_ans + s[right];
            left--;
            right++;
        }
        return (local_ans.size() > ans.size()) ? local_ans : ans;
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