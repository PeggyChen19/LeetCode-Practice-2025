class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) return false;
        int reversed = 0;
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        return (x == reversed) || (x == reversed / 10);
    }
};
/*
Palindrome -> read the same from left and from right
Don't convert int to string -> Space O(1)
Reverse the int and check if it's the same as original one
Improvement:
We only need reverse half of the int
*/