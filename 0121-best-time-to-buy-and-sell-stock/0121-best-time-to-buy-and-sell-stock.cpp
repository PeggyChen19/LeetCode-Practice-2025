class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0], maxProfit = 0;
        for (int price : prices) {
            maxProfit = max(maxProfit, price - minPrice);
            minPrice = min(minPrice, price);
        }
        return maxProfit;
    }
};

/*
target: maximize price[j] -  price[i], and j > i
只需要遍歷一次，紀錄目前走過最小的 price & max profit，然後把這個跟當下的相減更新 max
*/