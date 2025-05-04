class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int empty = 0, bought = -prices[0], cooldown = INT_MIN;
        int empty_new, bought_new, cooldown_new;
        for (int i = 1; i < prices.size(); i++) {
            empty_new = max(empty, cooldown);
            bought_new = max(bought, empty - prices[i]);
            cooldown_new = bought + prices[i];
            empty = empty_new;
            bought = bought_new;
            cooldown = cooldown_new;
        }
        return max(empty, cooldown);
    }
};
/*
Limit:
1. sell -> must cooldown the next day
2. only can hold one stock (must sell and then buy again)

Optimal substructure -> we can divide and conquer the problem and use DP
States: ind, max_profit, status(bought, empty, cooldown)
Decision:
1. buy
2. sell + cooldown
3. skip
Transition function: 
empty[i] = max(empty[i-1] // empty previously
               cooldown[i - i]) // completed cooldown
bought[i] = max(bought[i-1], // bought previously
                empty[i-1] - prices[i]) // buy now
cooldown[i] = bought[i-1] + prices[i] // sell previously and enter cooldown

Implement: Bottom-up
Memorization & Base Case:
empty_pre = 0
bought_pre = -price[0]
cooldown_pre = INT_MIN // invalid status
*/