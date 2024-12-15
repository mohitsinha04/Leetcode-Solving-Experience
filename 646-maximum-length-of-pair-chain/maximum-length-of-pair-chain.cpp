class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        auto cmp = [&] (const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        };
        
        sort(pairs.begin(), pairs.end(), cmp);
        
        int max_len = 1;
        int prev = pairs[0][1];
        
        for (int i= 1; i < pairs.size(); i++) {
            if (pairs[i][0] > prev) {
                max_len++;
                prev = pairs[i][1];
            }
        }
        
        return max_len;
        
        
    }
};