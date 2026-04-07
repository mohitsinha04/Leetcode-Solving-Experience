class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> res;

        backtrack(res, curr, nums, 0);
        return res;
    }

    void backtrack(vector<vector<int>>& res, vector<int>& curr, vector<int>& nums, int idx) {
        res.push_back(curr);

        for (int i = idx; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            backtrack(res, curr, nums, i + 1);
            curr.pop_back();
        }
    }
};