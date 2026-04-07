class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr = "";
        backtrack(res, curr, n, n);
        return res;
    }

    void backtrack(vector<string>& res, string& curr, int open, int close) {
        if (open == 0 && close == 0) {
            res.push_back(curr);
            return;
        }
        if (open > 0) {
            curr.push_back('(');
            backtrack(res, curr, open - 1, close);
            curr.pop_back(); // Backtrack
        }
        if (close > open) {
            curr.push_back(')');
            backtrack(res, curr, open, close - 1);
            curr.pop_back(); // Backtrack
        }
    }
};