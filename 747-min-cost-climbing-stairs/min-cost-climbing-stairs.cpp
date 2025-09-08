class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), 0);
        // dp[0] = cost[0];
        // dp[1] = cost[1];
        int a = cost[0];
        int b = cost[1];

        for (int i = 2; i < cost.size(); i++) {
            // if (i < 2) dp[i] = cost[i];
            // else
            //  dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
            int c = cost[i] + min(a, b);
            a = b;
            b = c;
        }
        // return min(dp[cost.size() - 1], dp[cost.size() - 2]);
        return min(a, b);
    }
};