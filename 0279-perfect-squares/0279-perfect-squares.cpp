class Solution {
public:
    int numSquares(int n) {
        if (n == 1) return 1;
        vector<int> memo(n + 1, INT_MAX);
        memo[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                memo[i] = min(memo[i], memo[i - j * j] + 1);
            }
        }
        return memo.back();
    }
};
/*
perfect square 1 4 9 16 25 
counts         a b c d  e

n = a * 1 + b * 4 + c * 9 + 16 * d + 25 * e
find min(a + b + c + d + e)

dynamic programming -> divide the problem

memo[i]: min # of perfect square nums sum to i (using all possible perfect squares)
for i = 1 to n
    memo[i] = INT_MAX
    for j = 1, j * j <= i; j++
        memo[i] = min(memo[i], memo[i - j * j] + 1)
*/