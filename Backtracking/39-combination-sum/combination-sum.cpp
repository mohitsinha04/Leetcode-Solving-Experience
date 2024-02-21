class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(res, curr, candidates, target, 0);
        return res;
    }
    void backtrack(vector<vector<int>>& res, vector<int>& curr, vector<int>& candidates, int target, int index) {
        if(target == 0) {
            res.push_back(curr);
            return;
        }
        if (target < 0 || index >= candidates.size()) return;
        for (int i = index; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            target -= candidates[i];
            backtrack(res, curr, candidates, target, i);
            target += candidates[i];
            curr.pop_back();
        }
    }
};