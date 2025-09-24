class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int profit = 0;
        int minP = prices[0], maxP = prices[0];
        for (int price : prices) {
            if (price < maxP) {
                profit += (maxP - minP);
                minP = price;
                maxP = price;
            }
            maxP = max(maxP, price);
            minP = min(minP, price);
        }
        profit += (maxP - minP);
        return profit;
    }
};
/*
max profit = max(price) - min(price)
Greedy
record min & max price
we can buy multiple times -> when there is an increasing subarray, buy with max - min


i i i d d d i i i
b   s     b     s

7 1 5 3 6 4
  ---|---
4 + 3 = 7
*/