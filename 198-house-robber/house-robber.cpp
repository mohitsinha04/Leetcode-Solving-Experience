class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        // vector<int> dp(nums.size());
        int dp2 = nums[0];
        int dp1 = max(nums[0], nums[1]);
        // dp[0] = nums[0];
        // dp[1] = max(nums[0], nums[1]);
        int res = max(dp1, dp2);
        for (int i = 2; i < nums.size(); i++) {
            // dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
            res = max(dp1, dp2 + nums[i]);
            dp2 = dp1;
            dp1 = res;
        }
        return res;
    }
};
