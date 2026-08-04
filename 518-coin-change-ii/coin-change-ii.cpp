class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int> (amount+1, -1));
        return helper(amount, coins, 0, dp);
    }

    int helper(int amount, vector<int>& coins, int index, vector<vector<int>>& dp) {
        if (amount == 0) return dp[index][amount] = 1;
        if (amount < 0 || index >= coins.size()) return 0;
        if (dp[index][amount] != -1) return dp[index][amount];
        int sum1 = 0;
        if (amount - coins[index] >= 0) sum1 = helper(amount - coins[index], coins, index, dp);
        int sum2 = helper(amount, coins, index + 1, dp);
        return dp[index][amount] = sum1 + sum2;
    }
};