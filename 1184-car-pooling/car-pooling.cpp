class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> line(1001, 0);
        for (auto trip : trips) {
            line[trip[1]] += trip[0];
            line[trip[2]] -= trip[0];
        }
        int currPassenger = 0;
        for (int i = 0; i < 1001; i++) {
            currPassenger += line[i];
            if (currPassenger > capacity) return false;
        }
        
        return true;
    }
};