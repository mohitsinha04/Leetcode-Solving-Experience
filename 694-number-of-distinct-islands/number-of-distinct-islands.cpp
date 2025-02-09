class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        unordered_set<string> islands;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    string island;
                    dfs(grid, i, j, i, j, island);
                    islands.insert(island);
                }
            }
        }
        return islands.size();
    }
    void dfs(vector<vector<int>>& grid, int i, int j, int currI, int currJ, string& island) {
        if (currI < 0 || currJ < 0 || currI >= grid.size() || currJ >= grid[0].size() || grid[currI][currJ] == 0) return;
        grid[currI][currJ] = 0;
        island += to_string(currI - i) + to_string(currJ - j);
        dfs(grid, i, j, currI + 1, currJ, island);
        dfs(grid, i, j, currI - 1, currJ, island);
        dfs(grid, i, j, currI, currJ + 1, island);
        dfs(grid, i, j, currI, currJ - 1, island);
    }
};