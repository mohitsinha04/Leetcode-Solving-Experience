class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        unordered_map<int, int> line;
        for (auto r : ranges) {
            line[r[0]]++;
            line[r[1] + 1]--;
        }
        int count = 0;
        
        for (int i = 0; i < 55; i++) {
            count += line[i];
            
            if (i >= left && i <= right && count == 0) return false;
        }
        return true;
    }
};