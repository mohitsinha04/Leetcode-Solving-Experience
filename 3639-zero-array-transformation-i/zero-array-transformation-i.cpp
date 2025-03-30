class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> line(nums.size() + 1, 0);
        for (auto q : queries) {
            line[q[0]]--;
            line[q[1] + 1]++;
        }

        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += line[i];
            if (sum + nums[i] > 0) return false;
        }
        return true;
    }
};