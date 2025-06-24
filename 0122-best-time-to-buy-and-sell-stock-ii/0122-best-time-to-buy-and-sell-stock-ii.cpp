class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i - 1] < prices[i]) {
                profit += (prices[i] - prices[i - 1]);
            }
        }
        return profit;
    }
};
/*
1. keep recording the min point
2. when encountering a peak -> sell it (profit = peak - min)
Improvement: don't need to find the exactly min point & peak -> just sum up all increasing intervals
*/