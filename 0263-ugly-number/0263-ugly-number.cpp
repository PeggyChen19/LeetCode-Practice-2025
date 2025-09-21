class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        vector<int> basicPrimes = {2, 3, 5};
        for (int prime : basicPrimes) {
            while (n % prime == 0) {
                n /= prime;
            }
            if (n == 1) return true;
        }
        return n == 1; 
    }
};
/*
ugly number n = 2^a * 3^b * 5^c
brute force:
try to dived n with 2, 3, 5 until it has remainder (not ugly) or it reaches 1 (ugly)
*/