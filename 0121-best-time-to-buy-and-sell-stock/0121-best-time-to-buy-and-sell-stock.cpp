class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curMin = prices[0];
        int globalMax = 0;
        for (int& price : prices) {
            globalMax = max(globalMax, price - curMin);
            curMin = min(curMin, price);
        }
        return globalMax;
    }
};
/*
go through the prices and record the curMin
use globalMax to track result
for all prices
    update globalMax
    update curMin
*/