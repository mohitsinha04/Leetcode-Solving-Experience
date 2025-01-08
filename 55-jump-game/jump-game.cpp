class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[nums.size() - 1] = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            int farthest = min(nums[i] + i, (int)nums.size() - 1);
            for (int j = i + 1; j <= farthest; j++) {
                if (dp[j] ==1) {
                    dp[i] = 1;
                    // break;
                }
            }
        }
        return dp[0] == 1;
    }
};

//print indices that you are jumping