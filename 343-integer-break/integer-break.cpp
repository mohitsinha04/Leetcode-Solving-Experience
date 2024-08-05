class Solution {
public:
    int integerBreak(int n) {
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        for(int j = 0;j < n+1; j++) dp[1][j] = 1;
        
        for (int i = 2; i < n; i++) {
            for (int sum = 0; sum <= n; sum++) {
                int notpick=dp[i-1][sum];
				int pick=0;
				if(sum>=i) pick=i*dp[i][sum-i];
				dp[i][sum]=max(pick,notpick);
            }
        }
        return dp[n-1][n];
    }
    int solve (int i, int sum_left, vector<vector<int>>& dp) {
        if (i == 1) return 1;
        if (dp[i][sum_left] != -1) return dp[i][sum_left];
        int notPick = solve(i - 1, sum_left, dp);
        int pick = 0;
        if (sum_left >= i) 
            pick = i * solve(i, sum_left - i, dp);
        return dp[i][sum_left] = max(notPick, pick);
    }
};