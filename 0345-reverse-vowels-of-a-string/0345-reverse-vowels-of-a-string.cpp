class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "aeiouAEIOU";
        int left = 0, right = s.size() - 1;
        while (left < right) {
            while (left < right && vowels.find(s[left]) == string::npos) left++; // keep moving until vowel
            while (left < right && vowels.find(s[right]) == string::npos) right--;
            if (left < right) {
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