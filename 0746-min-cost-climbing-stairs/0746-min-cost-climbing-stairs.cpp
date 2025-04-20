class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        int prev = 0, curr = 0;
        for (int i = 2; i <= size; i++) {
            int next = min(curr + cost[i-1], prev + cost[i-2]);
            prev = curr;
            curr = next;
        }
        return curr;
    }
};
/*
States: step(ind), total_cost
dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]) // the cost of going to step i
Target: reach size
Base case
dp[0] = 0
dp[1] = 0
*/