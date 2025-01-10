class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        vector<vector<int>> dp(events.size(), vector<int>(3, -1));
        return helper(events, 0, 0, dp);
    }
    int helper(vector<vector<int>>& events, int idx, int count, vector<vector<int>>& dp) {
        if (count == 2 || idx >= events.size()) return 0;

        if (dp[idx][count] != -1) return dp[idx][count];

        int end = events[idx][1];
        int left = idx + 1, right = events.size() - 1;

        while (left < right) {
            int mid = left + (right - left)/2;
            if (events[mid][0] > end) right = mid;
            else left = mid + 1;
        }
        int include = events[idx][2] + (left < events.size() && events[left][0] > end ?
                                        helper(events, left, count + 1, dp) : 0);
        int exclude = helper(events, idx + 1, count, dp);

        return dp[idx][count] = max(include, exclude);
    }
};