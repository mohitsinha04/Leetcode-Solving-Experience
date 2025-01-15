class Solution {
public:

    int maxTastiness(vector<int>& price, vector<int>& tastiness, int maxAmount, int maxCoupons) {
        vector<vector<vector<int>>> dp(price.size(), vector<vector<int>> (maxAmount + 1, vector<int> (maxCoupons + 1, -1)));
        return dfs(price, tastiness, 0, maxAmount, maxCoupons, dp);
    }

    int dfs(vector<int>& price, vector<int>& tastiness, int idx, int maxAmount, int maxCoupons, vector<vector<vector<int>>> &dp){
        if(idx == price.size()) return 0;
        if(dp[idx][maxAmount][maxCoupons] != -1) return dp[idx][maxAmount][maxCoupons];

        int notTake = dfs(price, tastiness, idx + 1, maxAmount, maxCoupons, dp);
        
        int take = 0, takeCoupon = 0;
        if(price[idx] <= maxAmount){
            take = tastiness[idx] + dfs(price, tastiness, idx + 1, maxAmount - price[idx], maxCoupons, dp);
        }
        if(maxCoupons > 0 && price[idx]/2 <= maxAmount){
            takeCoupon = tastiness[idx] + dfs(price, tastiness, idx + 1, maxAmount - price[idx]/2, maxCoupons-1, dp);
        }
        return dp[idx][maxAmount][maxCoupons] = max({take, takeCoupon, notTake});
    }
};