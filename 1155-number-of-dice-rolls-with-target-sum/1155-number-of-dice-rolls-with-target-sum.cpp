class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int mod = (int)pow(10, 9) + 7;
        vector<int> memo(target+1, 0);
        memo[0] = 1; // for no dice -> only can combine to 0 with one way
        for (int i = 0; i < n; i++) {
            int sub_sum = 0;
            vector<int> next_memo(target+1, 0);
            for (int t = 1; t <= target; t++) {
                sub_sum = (sub_sum + memo[t - 1]) % mod; // sliding window: add element
                if (t-k-1 >= 0) {
                    sub_sum = (sub_sum - memo[t-k-1] + mod) % mod; // sliding window: delete
                }
                next_memo[t] = sub_sum;
            }
            memo = next_memo;
        }
        return memo[target];
    }
};
/*
1. State & Subproblem
state: index, face, cur_sum
subproble: the number of way to sum up to target using dice 0~i
2. Decision
for each dice, choose from 1~k
3. State Transition Function
memo[dice][sum] = sum of (memo[dice-1][sum-f]) for all f from 1 to k
4. Base Case
memo[0] = 1
5. Computational Sequence (bottom-up / top-down)
for all dices
    for all sums (reverse)
        memo[sum] = 0
        for all faces
            memo[sum] += memo[sum-face]
6. Memorization - build a lookup table
1d memo vector
7. Improvement
for all dices
    for all faces
        sub_sum += memo[sum-face]
    for all sums (reverse)
        memo[sum] = sub_sum
        update sub_sum (sliding window)

1 2 3 4 5 6 
-------------
1 1 1 1 1 1
^ ^ ^ ^
0 1 2 3
 
2: 1+1
3: 1+2, 2+1
4: 1+3, 2+2, 3+1
*/