class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> map;
        for (int i = 0; i < s.size(); i++) {
            map[s[i]] = i; 
        }
        vector<int> res;
        int j = 0, anchor = 0;
        for (int i = 0; i < s.size(); i++) {
            j = max(j, map[s[i]]);
            if (i == j) {
                res.push_back(i - anchor + 1);
                anchor = i + 1;
            }
        }
        return res;
    }
};