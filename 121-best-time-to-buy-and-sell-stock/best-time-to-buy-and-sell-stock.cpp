class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int min_so_far = prices[0];
        int max_profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > min_so_far) {
                max_profit = max(max_profit, prices[i] - min_so_far);
            }
            min_so_far = min(prices[i], min_so_far);
        }
        return max_profit;
    }
};