class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currMin = prices[0];
        int res = INT_MIN;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < currMin) currMin = prices[i];
            res = max(res, prices[i] - currMin);
        }
        return res == INT_MIN ? 0 : res;
    }
};