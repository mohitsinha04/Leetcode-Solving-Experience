class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        // vector<int> dp(n), dpPrev(n);

        // for (int i = n - 1; i >= 0; i--) {
        //     dp[i] = 1;
        //     for (int j = i + 1; j < n; j++) {
        //         if (s[i] == s[j]) {
        //             dp[j] = dpPrev[j-1] + 2;
        //         } else {
        //             dp[j] = max(dpPrev[j], dp[j-1]);
        //         }
        //     }
        //     dpPrev = dp;
        // }
        // return dp[n-1];
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};