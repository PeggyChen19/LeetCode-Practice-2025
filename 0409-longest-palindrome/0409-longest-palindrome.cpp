class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> counts;
        for (auto& ch : s) {
            counts[ch]++;
        }
        int result = 0;
        bool hasOdd = false;
        for (auto& [ch , count] : counts) {
            result += count;
            if (count % 2) { // odd
                hasOdd = true;
                result--;
            }
        }
        result += hasOdd;
        return result;
    }
};
/*
Palindrome -> all char must be even, with only 1 exception at the center
Use unordered_map to record the counts of each char
Time: O(n)
Space: O(alphabet)
*/