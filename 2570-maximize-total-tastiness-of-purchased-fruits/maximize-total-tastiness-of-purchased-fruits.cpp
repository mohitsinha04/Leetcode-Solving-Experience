class Solution {
public:
    int maxTastiness(vector<int>& price, vector<int>& tastiness, int barAmount, int couponMax) {
        vector<vector<vector<int>>> dp(price.size()+1, vector<vector<int>> (barAmount + 1, vector<int> (couponMax + 1, 0)));
        int n = price.size();
        
        for(int idx = n-1;idx>=0;idx--){
            for(int maxAmount = barAmount; maxAmount >=0; maxAmount--){
                for(int maxCoupons = couponMax; maxCoupons >=0; maxCoupons--){
                        
                        int notTake = dp[idx + 1][maxAmount][maxCoupons];
                        int take = 0, takeCoupon = 0;
                        if(price[idx] <= maxAmount){
                            take = tastiness[idx] + dp[idx + 1][maxAmount - price[idx]][maxCoupons];
                        }
                        if(maxCoupons > 0 && price[idx]/2 <= maxAmount){
                            takeCoupon = tastiness[idx] + dp[idx + 1][maxAmount - price[idx]/2][maxCoupons-1];
                        }
                        dp[idx][maxAmount][maxCoupons] = max({take, takeCoupon, notTake});
                }
            }
        }
        return dp[0][barAmount][couponMax];
    }
};