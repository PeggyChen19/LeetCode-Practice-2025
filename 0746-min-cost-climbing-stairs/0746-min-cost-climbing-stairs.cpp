class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        int prev_one = 0, prev_two = 0;
        for (int i = 2; i < size; i++) {
            int tmp = prev_one;
            prev_one = min(prev_one + cost[i-1], prev_two + cost[i-2]);
            prev_two = tmp;
        }
        return min(prev_one + cost[size-1], prev_two + cost[size-2]);
    }
};
/*
10, 15, 20
one: 0 10 25
two: 0 0 15

States: step, total_cost
dp[s] = min(dp[s-1] + cost[s-1], dp[s-2] + cost[s-2])
Target: reach size -> come from min(dp[size-1)] + cost[size-1], dp[size-2] + cost[size-2])
Base case
dp[0] = 0
dp[1] = 0

*/