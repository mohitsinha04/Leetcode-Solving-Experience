class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> line(length, 0);
        for (auto update : updates) {
            line[update[0]] += update[2];
            if (update[1] + 1 < length)
                line[update[1] + 1] -= update[2];
        }
        
        for (int i = 1; i < length; i++) {
            line[i] += line[i-1];
        }
        return line;
    }
};