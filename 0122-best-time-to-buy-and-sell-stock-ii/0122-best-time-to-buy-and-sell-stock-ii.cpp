class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minPrice = INT_MAX;
        for (int i = 0; i < prices.size() - 1; i++) {
            minPrice = min(minPrice, prices[i]);
            if (prices[i] > prices[i + 1]) {
                profit += (prices[i] - minPrice);
                minPrice = INT_MAX;
            }
        }
        if(minPrice != INT_MAX) {
            profit += (prices.back() - minPrice);
        }
        return profit;
    }
};
/*
On each day, you may decide to buy and/or sell the stock. 
You can only hold at most one share of the stock at any time. 
Find and return the maximum profit you can achieve.

[7   1   5   7   3   6   9]
1. keep recording the min point
2. when encountering a peak -> sell it (profit = peak - min)
*/