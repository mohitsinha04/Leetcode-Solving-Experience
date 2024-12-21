class Solution {
public:
    // q[0] = i;
    // q[1] = j;
    // q[2] = curr_level;
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        
        vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        queue<vector<int>> q;
        
        for (int i = 0; i < rooms.size(); i++) {
            for (int j = 0; j < rooms[0].size(); j++) {
                if (rooms[i][j] == 0) q.push({i, j});
            }
        }
        
        int level = 0;
        
        while (!q.empty()) {
            vector<int> curr = q.front();
            q.pop();
                
            for (auto d : dir) {
                int x = curr[0] + d[0];
                int y = curr[1] + d[1];
                    
                if (x >= 0 && y >= 0 && x < rooms.size() && y < rooms[0].size() && rooms[x][y] == INT_MAX) {
                    rooms[x][y] = rooms[curr[0]][curr[1]] + 1;
                    q.push({x, y});
                }
            }
        }
    }
};