bool isAlphaNum(char c) {
    if (('0' <= c && c <= '9') || ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
        return true;
    } else {
        return false;
    }
}


class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left <= right) {
            if (!isAlphaNum(s[left])) {
                left++;
            } else if (!isAlphaNum(s[right])) {
                right--;
            } else {
                if (tolower(s[left]) == tolower(s[right])) {
                    left++;
                    right--;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

/*
palindrome is symmetric string
use two pointer(left & right) to check if it's symmectric or not

left: beginning of the str
right: end of the str
while left <= right
    omit non-alpanumeric
    if left == right
        left++
        right--
    else
        return false
return true
*/