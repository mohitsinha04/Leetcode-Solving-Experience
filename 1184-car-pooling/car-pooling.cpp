class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> line;

        for (auto trip : trips) {
            line[trip[1]] += trip[0];
            line[trip[2]] -= trip[0];
        }
        int count = 0;
        for (auto m : line) {
            count += m.second;
            if (count > capacity) return false;
        }
        return true;
    }
};