class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<int> factors = {n};
        vector<vector<int>> res;
        backtrack(factors, res);
        return res;
    }
    void backtrack(vector<int>& factors, vector<vector<int>>& res) {
        if (factors.size() > 1) {
            res.push_back(factors);
        }
        int lastFactor = factors.back();
        factors.pop_back();
        
        for (int i = factors.empty() ? 2 : factors.back(); i <= lastFactor / i; i++) {
            if (lastFactor % i == 0) {
                factors.push_back(i);
                factors.push_back(lastFactor / i);
                backtrack(factors, res);
                factors.pop_back();
                factors.pop_back();
            }
        }
        factors.push_back(lastFactor);
    }
};