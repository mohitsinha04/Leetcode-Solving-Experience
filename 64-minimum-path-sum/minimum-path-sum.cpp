class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), grid[0][0]));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < grid.size(); i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for (int j = 1; j < grid[0].size(); j++) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }

        for (int i = 1; i < grid.size(); i++) {
            for (int j = 1; j < grid[0].size(); j++) {
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
    int helper(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
        if (dp[i][j] != -1) return dp[i][j];

        if (i == grid.size() -1 && j == grid[0].size() - 1) return grid[i][j];

        int res1 = INT_MAX;
        if (i + 1 < grid.size()) {
            res1 = helper(grid, i +1, j, dp);
        }
        int res2 = INT_MAX;
        if (j + 1 < grid[0].size()) {
            res2 = helper(grid, i, j + 1, dp);
        }
        return dp[i][j] = min(res1, res2) + grid[i][j];
    }
};
// if (i == grid.size() -1 && j == grid[0].size() - 1) return grid[i][j];
// rec(i, j) = grid[i][j] + min(rec(i+1, j), rec(i, j+1));
