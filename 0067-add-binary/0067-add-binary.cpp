class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int indA = a.size() - 1;
        int indB = b.size() - 1;
        int carry = 0;
        while (indA >= 0 || indB >= 0 || carry) {
            int valA = (indA >= 0 && a[indA] == '1') ? 1 : 0;
            int valB = (indB >= 0 && b[indB] == '1') ? 1 : 0;
            int sum = valA + valB + carry;
            carry = (sum >= 2) ? 1 : 0;
            result += (sum % 2) ? '1' : '0';
            indA--;
            indB--;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
/*
Add them from right to left
Use int var carry
*/