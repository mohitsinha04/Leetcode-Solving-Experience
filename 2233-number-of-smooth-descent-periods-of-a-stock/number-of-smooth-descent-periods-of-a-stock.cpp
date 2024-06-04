class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        // vector<int> dp(prices.size(), 1);
        int dp = 1;
        long long res = 1;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i-1] - prices[i] == 1) {
                dp++;
            } else dp = 1;
            res += dp;
        }
        return res;
    }
};