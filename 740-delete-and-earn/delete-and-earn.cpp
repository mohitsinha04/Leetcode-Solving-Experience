class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> bucket(10001, 0);
        for (int i : nums) {
            bucket[i] += i;
        }
        vector<int> dp(10001, 0);
        dp[0] = bucket[0];
        dp[1] = bucket[1];
        for (int i = 2; i < 10001; i++) {
            dp[i] = max(bucket[i] + dp[i-2], dp[i-1]);
        }
        return dp[10000];
    }
};