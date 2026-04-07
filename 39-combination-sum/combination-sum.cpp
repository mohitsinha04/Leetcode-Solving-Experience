class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        int i = 0;

        backtrack(res, curr, candidates, target, 0);
        return res;
    }

    void backtrack(vector<vector<int>>& res, vector<int>& curr, vector<int>& candidates, int target, int idx) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }
        if (target < 0) return;

        for (int i = idx; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            backtrack(res, curr, candidates, target - candidates[i], i);
            curr.pop_back();
        }
    }
};