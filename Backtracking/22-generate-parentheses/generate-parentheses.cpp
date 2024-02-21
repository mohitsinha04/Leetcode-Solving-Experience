class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s = "";
        backtrack(res, s, 0, 0, n);
        return res;
    }
    void backtrack(vector<string>& res, string curr, int open, int close, int n) {
        if (curr.size() == n + n) {
            res.push_back(curr);
            return;
        }
        if (open < n) {
            curr += "(";
            backtrack(res, curr, open + 1, close, n);
            curr.pop_back();
        } 
        if (close < open){
            curr += ")";
            backtrack(res, curr, open, close + 1, n);
            curr.pop_back();
        }
        
    }
};