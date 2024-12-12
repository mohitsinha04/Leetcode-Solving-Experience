class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> line(100, 0);
        
        for (auto range : ranges) {
            line[range[0]]++;
            line[range[1] + 1]--;
        }
        
        int count = 0;
        
        for (int i = 0; i < 55; i++) {
            count += line[i];
            
            if (i >= left && i <= right && count == 0) return false;
        }
        return true;
    }
};