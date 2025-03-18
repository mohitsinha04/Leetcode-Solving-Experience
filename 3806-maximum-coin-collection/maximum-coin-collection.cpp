class Solution {
public:
    long long dp[100001][2][3];
    long long helper(int index, int lane, int s, vector<int>& lane1, vector<int>& lane2) {
        if(index == lane1.size()) return 0;
        if(s < 0) return 0;
        long long ans = LLONG_MIN;
        if(dp[index][lane][s] != -1) return dp[index][lane][s];
        if(lane == 0) {
            ans = max(ans, lane1[index] + helper(index + 1, lane, s, lane1, lane2));
            ans = max(ans, helper(index, 1, s - 1, lane1, lane2));
        }
        else {
            ans = max(ans, lane2[index] + helper(index + 1, lane, s, lane1, lane2));
            ans = max(ans, helper(index, 0, s - 1, lane1, lane2));
        }
        return dp[index][lane][s] = ans;
    }
    long long maxCoins(vector<int>& lane1, vector<int>& lane2) {
        long long ans = LLONG_MIN;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < lane1.size(); i++) {
            ans = max(ans, helper(i, 0, 2, lane1, lane2));
        }
        if(ans == 0) {
            long long ans1 = LLONG_MIN;
            for(int i = 0; i < lane1.size(); i++) {
                ans1 = max(ans1, (long long)max(lane1[i], lane2[i]));
            }
            return ans1;
        }
        return ans;
    }
};