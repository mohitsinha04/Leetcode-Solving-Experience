class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() < 1) return 0;
        vector<int> dp(nums.size());
        int ans = 1;
        for (int i = 0; i < dp.size(); i++) {
            int max1 = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    max1 = max(max1, dp[j] + 1);
                }
            }
            dp[i] = max1;
            ans = max(ans, max1);
        }
        return ans;
    }
};