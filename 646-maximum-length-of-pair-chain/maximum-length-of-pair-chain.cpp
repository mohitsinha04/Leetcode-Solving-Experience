class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<int> dp(pairs.size() + 1, 0);
        dp[pairs.size() - 1] = 1;
        
        for (int i = pairs.size() - 2; i >= 0; i--) {
            int exclude = dp[i+1];
            int next = binarySearch(pairs, i);
            int include = dp[next] + 1;
            dp[i] = max(exclude, include);
        }
        return dp[0];
    }
    int binarySearch(vector<vector<int>>& pairs, int curr_index) {
        int left = curr_index + 1, right = pairs.size() - 1;
        int res = pairs.size();
        
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (pairs[mid][0] > pairs[curr_index][1]) {
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return res;
    }
};