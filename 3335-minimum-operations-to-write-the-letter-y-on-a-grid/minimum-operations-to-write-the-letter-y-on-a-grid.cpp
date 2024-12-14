class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        return min ({trythis(grid, 0, 1), trythis(grid, 0, 2),
                    trythis(grid, 1, 0), trythis(grid, 1, 2), 
                    trythis(grid, 2, 0), trythis(grid, 2, 1)});
    }
    
    int trythis(vector<vector<int>> grid, int x, int y) {
        int curr_cost = 0, n = grid.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((i <= n/2 && (i == j || i + j == n-1)) || 
                   (i > n/2 && j == n/2)) {
                    if (grid[i][j] != x) curr_cost++;
                } else {
                    if (grid[i][j] != y) curr_cost++;
                }
            }
        }
        
        return curr_cost;
    }
};