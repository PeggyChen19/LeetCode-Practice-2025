class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int original = x;
        int reversed = 0;
        while (x > 0) {
            int lastDigit = x % 10;
            x /= 10;
            if (reversed > (INT_MAX - lastDigit) / 10) return false; // overflow
            reversed = reversed * 10 + lastDigit;
        }
        return original == reversed;
    }
};
/*
Palindrome -> read the same from left and from right
Don't convert int to string -> Space O(1)
Reverse the int and check if it's the same as original one
*/