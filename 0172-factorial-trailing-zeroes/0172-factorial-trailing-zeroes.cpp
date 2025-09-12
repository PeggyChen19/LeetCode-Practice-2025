class Solution {
public:
    int trailingZeroes(int n) {
        int interval = 5;
        int fiveCount = 0;
        while (interval <= n) {
            fiveCount += (n / interval);
            interval *= 5;
        }
        return fiveCount;
    }
};
/*
n! (factorial of n) = 1 * 2 * 3 ... n
the prime factorization of n! is 2^x * 5^y * ...
the min(x, y) will be the number of 0 at the back
x must be larger than y -> find y only

every 5 element: have 1 five in the prime factorization
every 25 (5^2): have 2 fives in the prime factorization
every 125(5^3): have 3 fives in the prime factorization

  1 2 3 4 5 ... 10 ... 15 ... 20 ... 25 ... 30 ....
5 --------1-----1------1------1------1-------1
25 ----------------------------------1-------
*/