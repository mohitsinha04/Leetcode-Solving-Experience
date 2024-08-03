class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.size() <= 0) return 0;
        sort(pairs.begin(), pairs.end());
        
        vector<int> lis(pairs.size(), 1);
        int res = 1;
        
        for (int i = 1; i < pairs.size(); i++) {
            for (int j = 0; j < i; j++) {
                if ((pairs[j][1] < pairs[i][0]) && (lis[i] < lis[j] + 1)) {
                    lis[i] = lis[j] + 1;
                    res = max(lis[i], res);
                }
            }
        }
        return res;
    }
};