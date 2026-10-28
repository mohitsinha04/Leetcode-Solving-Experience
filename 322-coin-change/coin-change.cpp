class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int INF = amount + 1;
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;

        for (int coin : coins) {
            for (int t = coin; t <= amount; ++t) {
                dp[t] = min(dp[t], dp[t - coin] + 1);
            }
        }

        return dp[amount] == INF ? -1 : dp[amount];
    }
};