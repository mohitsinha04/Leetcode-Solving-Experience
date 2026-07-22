class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> dp(grid[0].size(), grid[0][0]);
        
        for (int i = 1; i < grid[0].size(); i++) {
            dp[i] = dp[i-1] + grid[0][i];
        }

        for (int i = 1; i < grid.size(); i++) {
            dp[0] += grid[i][0];

            for (int j = 1; j < grid[0].size(); j++) {
                dp[j] = min(dp[j], dp[j-1]) + grid[i][j];
            }
        }
        return dp[grid[0].size() - 1];
    }
};