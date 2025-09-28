class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int nextNum = 0;
            while (num) {
                int digit = num % 10;
                nextNum += digit;
                num /= 10;
            }
            num = nextNum;
        }
        return num;
    }
};
/*
get the lowest digit by mod 10
keep calculating
*/