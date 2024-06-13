class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        
        for (int c : coins) {
            for (int j = 0; j < amount + 1; j++) {
                if (j >= c) {
                    dp[j] += dp[j-c];
                }
            }
        }
        
        return dp[amount];
    }
};