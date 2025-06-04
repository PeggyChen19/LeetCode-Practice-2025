class Solution {
public:
    int longestPalindrome(string s) {
        int oddCount = 0;
        unordered_map<char, int> counts;
        for (auto& ch : s) {
            counts[ch]++;
            if (counts[ch] % 2) {
                oddCount++;
            } else {
                oddCount--;
            }
        }
        return s.size() - oddCount + 1;
    }
};
/*
Palindrome -> all char must be even, with only 1 exception at the center
Use unordered_map to record the counts of each char
Time: O(n)
Space: O(alphabet)
*/