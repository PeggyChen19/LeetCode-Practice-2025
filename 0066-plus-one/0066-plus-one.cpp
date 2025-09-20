class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        int i = n - 1;
        while (i >= 0 && carry) {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
            i--;
        }
        if (carry) digits.insert(digits.begin(), 1);
        return digits;
    }
};
/*
add one (from rightmost)
go from right to left until no carry
if having carry after go through all digits -> push_front
*/