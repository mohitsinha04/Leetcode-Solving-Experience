class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        int curr_perf_sq = 1;
        while (curr_perf_sq * curr_perf_sq <= n) {
            int square = curr_perf_sq * curr_perf_sq;
            for (int i = square; i <= n; i++) {
                dp[i] = min(dp[i - square] + 1, dp[i]);
            }
            curr_perf_sq++;
        }
        return dp[n];
    }
};


// 0 -> 0; (dp[0])
// 1 -> 1; (dp[0] + 1);
// 2 -> 1 + 1 = 2; (dp[1] + 1);
// 3 -> 1 + 1 + 1 = 3; (dp[2] + 1);
// 4 -> 4 = 1; if perfect_square(4) ? 1 : dp[3] + 1
// 5 -> 4 + 1 = 2;
// 6 -> 4 + 1 + 1 = 3;
// 7 -> 4 + 1 + 1 + 1 = 4;
// 8 -> 4 + 4 = 2;
// 9 -> min(9, 4 + 4 + 1) = 1;
// 10 -> min(9 + 1, 4 + 4 + 1 + 1) = 2;
// 11 -> min(9 + 1 + 1, 4 + 4 + 1 + 1 + 1) = 3;
// 12 -> min(9 + 1 + 1 + 1, 4 + 4 + 4) = 3;
