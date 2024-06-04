class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        vector<int> dp(prices.size(), 1);
        dp[0] = 1;
        long long res = 1;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i-1] - prices[i] == 1) {
                dp[i] = dp[i-1] + 1;
            } 
            res += dp[i];
        }
        return res;
    }
};