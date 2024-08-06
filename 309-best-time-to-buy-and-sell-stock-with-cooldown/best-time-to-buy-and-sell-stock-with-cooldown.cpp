class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        vector<int> dp(prices.size(), -1);
        bool cooldown = false;
        return helper(prices, 0, dp);
    }
    int helper(vector<int>& prices, int pos, vector<int>& dp) {
        if (pos >= prices.size()) return 0;
        int res = 0;
        if (dp[pos] != -1) return dp[pos];
        for (int i = pos + 1; i < prices.size(); i++) {
            if (prices[i] > prices[pos]) {
                res = max(prices[i] - prices[pos] + helper(prices, i + 2, dp), res);
            } else {
                res = max(res, helper(prices, pos + 1, dp));
            }
        }
        return dp[pos] = res;
    }
};
// int maxProfit(vector<int>& prices, int pos){
//         int n=prices.size();
//         if(pos>=n)return 0;
        
//         int ans=0;
// for(int i=pos+1;i<n;i++){
//     if(prices[i]>prices[pos]){
//         ans=max(prices[i]-prices[pos]+maxProfit(prices, i+2), ans);
//             }
//     else{
//         ans=max(ans, maxProfit(prices, pos+1));
//     }
//         }
//         return ans;
//     }
    
//     int maxProfit(vector<int>& prices) {
//         return maxProfit(prices, 0);
//     }