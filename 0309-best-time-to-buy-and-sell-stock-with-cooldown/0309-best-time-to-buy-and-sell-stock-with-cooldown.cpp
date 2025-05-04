class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int empty_pre = 0, bought_pre = -prices[0], cooldown_pre = 0;
        int empty_cur, bought_cur, cooldown_cur;
        for (int i = 1; i < prices.size(); i++) {
            empty_cur = max(empty_pre, cooldown_pre);
            bought_cur = max(bought_pre, empty_pre - prices[i]);
            cooldown_cur = bought_pre + prices[i];
            swap(empty_cur, empty_pre);
            swap(bought_cur, bought_pre);
            swap(cooldown_cur, cooldown_pre);
        }
        return max(empty_pre, cooldown_pre);
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
cooldown_pre = 0
*/