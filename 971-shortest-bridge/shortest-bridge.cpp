class Solution {
public:
    int n;
    int directions[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
    queue<vector<int>> q;

    void dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& visited) {
        visited[r][c] = true;
        for (auto& dir : directions) {

            int nr = r + dir[0], nc = c + dir[1];

            if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                if (grid[nr][nc] == 0) {
                    visited[nr][nc] = true;
                    q.push({nr, nc, 1});
                    // return;
                } else {
                    dfs(grid, nr, nc, visited);
                }
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        bool found = false;

        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, visited);
                    found = true;
                    break;
                }
            }
        }

        while (!q.empty()) {
            auto curr = q.front(); 
            q.pop();
            int r = curr[0], c = curr[1], dist = curr[2];

            for (auto& dir : directions) {
                int nr = r + dir[0], nc = c + dir[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    if (grid[nr][nc] == 1) return dist;
                    visited[nr][nc] = true;
                    q.push({nr, nc, dist + 1});
                }
            }
        }
        return 0;
    }
};