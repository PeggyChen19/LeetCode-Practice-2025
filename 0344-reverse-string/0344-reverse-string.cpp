class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};
/*
method 1
reverse function

method 2
two pointer, left & right
swap(left, right) until left >= right
*/