class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr = "";
        helper(res, curr, n, n);
        return res;
    }

    void helper(vector<string>& res, string curr, int open, int close) {
        if (open == 0 && close == 0) {
            res.push_back(curr);
            return;
        }

        if (open > 0) {
            helper(res, curr + '(', open - 1, close);
        }
        if (close > open) {
            helper(res, curr + ')', open, close - 1);
        }
    }
};