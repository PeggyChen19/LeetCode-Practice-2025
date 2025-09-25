class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int left = 0, right = s.size() - 1;
        while (left < right) {
            while (left < right && !vowel.count(s[left])) left++; // keep moving until vowel
            while (left < right && !vowel.count(s[right])) right--;
            if (left < right && vowel.count(s[left]) && vowel.count(s[right])) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};
/*
two pointers, left & right
move them to the vowels, swap
end when left >= right

unordered_set vowel = {'a', 'e', ...}
left = 0, right = size - 1
while (left < right)
    while (left < right && !vowel.count(s[left])) left++
    while (left < right && !vowel.count(s[right])) right--
    if (left < right && vowel.count(s[left]) && vowel.count(s[right]))
        swap(s[left], s[right])
        left++
        right--
*/