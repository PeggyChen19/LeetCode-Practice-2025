class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left <= right) {
            if (!isalnum(s[left])) {
                left++;
            } else if (!isalnum(s[right])) {
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