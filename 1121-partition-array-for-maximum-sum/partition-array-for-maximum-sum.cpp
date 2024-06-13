class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(), -1);
        return dfs(arr, k, dp, 0);
    }
    int dfs(vector<int>& arr, int k, vector<int>& dp, int curr_index) {
        if (curr_index >= arr.size()) return 0;
        if (dp[curr_index] != -1) return dp[curr_index];
        
        int curr_max = arr[curr_index];
        int res = 0;
        int end = min(curr_index + k, (int)arr.size());
        for (int i = curr_index; i < end; i++) {
            curr_max = max(curr_max, arr[i]);
            res = max(res, curr_max * (i - curr_index + 1) + dfs(arr, k, dp, i + 1));
        }
        return dp[curr_index] = res;
    }
};