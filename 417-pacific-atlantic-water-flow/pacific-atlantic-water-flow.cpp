class Solution {
public:
    vector<vector<int>> dir{{0,1}, {1,0}, {-1,0}, {0,-1}};
    vector<vector<int>> landHeights;
    int rows;
    int cols;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.size() == 0 || heights[0].size() == 0) {
            return {};
        }
        rows = heights.size();
        cols = heights[0].size();
        landHeights = heights;

        queue<vector<int>> pq;
        queue<vector<int>> aq;

        for (int i = 0; i < rows; i++) {
            pq.push({i, 0});
            aq.push({i, cols - 1});
        }
        for (int i = 0; i < cols; i++) {
            pq.push({0, i});
            aq.push({rows - 1, i});
        }

        vector<vector<bool>> pr = bfs(pq);
        vector<vector<bool>> ar = bfs(aq);

        vector<vector<int>> res;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pr[i][j] && ar[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }

    vector<vector<bool>> bfs(queue<vector<int>>& q) {
        vector<vector<bool>> reachable(rows, vector<bool>(cols, false));

        while (!q.empty()) {
            vector<int> curr = q.front();
            q.pop();

            reachable[curr[0]][curr[1]] = true;
            for (auto d : dir) {
                int x = curr[0] + d[0];
                int y = curr[1] + d[1];

                if (x < 0 || x >= rows || y < 0 || y >= cols || reachable[x][y]) continue;

                if (landHeights[x][y] < landHeights[curr[0]][curr[1]]) {
                    continue;
                }
                q.push({x, y});
            }
        }
        return reachable;
    }
};