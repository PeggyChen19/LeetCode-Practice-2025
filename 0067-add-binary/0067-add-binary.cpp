class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) swap(a, b); // let a.size >= b
        int indA = a.size() - 1;
        int indB = b.size() - 1;
        int carry = 0;
        while (indB >= 0 || carry) {
            int valB = (indB >= 0 && b[indB] - '0') ? 1 : 0;
            if (indA < 0) {
                a = "1" + a;
                break;
            }
            int sum = (a[indA] - '0') + valB + carry;
            if (sum >= 2) carry = 1;
            else carry = 0;
            a[indA] = (sum % 2) ? '1' : '0';
            indA--;
            indB--;
        }
        return a;
    }
};
/*
Add them from right to left
Use int var carry
*/