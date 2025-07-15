class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curMin = prices[0], curMax = prices[0];
        int globalMax = 0;
        for (int& price : prices) {
            if (price > curMax) {
                curMax = price;
                globalMax = max(globalMax, curMax - curMin);
            }
            if (price < curMin) {
                curMin = price;
                curMax = price;
            }
        }
        return globalMax;
    }
};
/*
go through the prices and record the current min & max
use globalMax to store result
when max is updated, calculate new profit
when min is needed to update, set max to min
*/