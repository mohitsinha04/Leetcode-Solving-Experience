class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        int n = 0;
        
        for (auto trip : trips) n = max(trip[2], n);
        
        vector<int> line(n + 1, 0);
        
        for (auto trip : trips) {
            line[trip[1]] += trip[0];
            line[trip[2]] -= trip[0];
        }
        
        if (line[0] > capacity) return false;
        
        for (int i = 1; i <= n; i ++) {
            line[i] += line[i-1];
            
            if (line[i] > capacity) return false;
        }
        
        return true;
    }
};