class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        // dp[0][0] = grid[0][0];
        return helper(grid, 0, 0, dp);
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
