class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> res;
        
        backtrack(curr, res, nums, 0);
        return res;
    }
    void backtrack(vector<int>& curr, vector<vector<int>>& res, vector<int>& nums, int index) {
        res.push_back(curr);
        for (int i = index; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            backtrack(curr, res, nums, i + 1);
            curr.pop_back();
        }
    }
};