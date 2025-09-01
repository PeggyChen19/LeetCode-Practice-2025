class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int mod = 1000000007;
        vector<int> dpPre(target + 1, 0);
        vector<int> dpCur(target + 1, 0);
        dpPre[0] = 1; // no dice
        for (int i = 0; i < n; i++) {
            int sub_sum = 0;
            for (int j = 1; j <= target; j++) {
                sub_sum = (sub_sum + dpPre[j - 1]) % mod; // add element
                if (j - (k + 1) >= 0) {
                    sub_sum = (sub_sum - dpPre[j - (k + 1)] + mod) % mod; // remove element
                }
                dpCur[j] = sub_sum;
            }
            dpPre = dpCur;
            fill(dpCur.begin(), dpCur.end(), 0);
        }
        return dpPre[target];
    }
};
/*
divide the problem into subproblem -> dp
states: the number of dice used (i), the current sum (s)
transiction function:
dp[i][s] = sum(dp[i-1][s - face]), for face from 1 to k
implement:
for all dice
    for all sum
        for all face
improvement:
for the sum of all face, this is the sum of a continuous array, we can utilize the concept of sliding window, in that case, we don't need to calculate the sum from scratch everytime
memorization:
two 1D array
dp[pre][s]
dp[cur][s]
*/