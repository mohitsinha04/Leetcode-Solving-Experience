class Solution {
public:
    vector<vector<int>> dir{{-1,0},{1,0},{0,-1},{0,1}};

    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        int fresh = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) q.push({i, j});
                if (grid[i][j] == 1) fresh++;
            }
        }

        int level = 0;

        while (!q.empty() && fresh > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto coord = q.front();
                q.pop();
                int n = coord[0], m = coord[1];

                for (auto d : dir) {
                    int x = n + d[0];
                    int y = m + d[1];

                    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != 1) {
                        continue;
                    }
                    q.push({x,y});
                    grid[x][y] = 2;
                    fresh--;
                }
            }
            level++;
        }
        return fresh == 0 ? level : -1;
    }
};