class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end()); // Sort by start time

        // Dynamic Programming array
        vector<long long> dp(n + 1, 0);

        // Map to store rides ending at each point
        vector<vector<pair<int, int>>> rideEndMap(n + 1);

        for (auto& ride : rides) {
            int start = ride[0], end = ride[1], tip = ride[2];
            rideEndMap[end].emplace_back(start, tip);
        }

        for (int i = 1; i <= n; ++i) {
            // Carry forward the previous profit
            dp[i] = dp[i - 1];

            // Check all rides that end at point i
            for (auto& [start, tip] : rideEndMap[i]) {
                dp[i] = max(dp[i], dp[start] + (i - start + tip));
            }
        }

        return dp[n];
    }
    long long dfs(int idx, vector<vector<int>>& rides, vector<long long>& memo) {
        if (idx >= rides.size()) {
            return 0; // Base case
        }
        if (memo[idx] != -1) {
            return memo[idx]; // Return cached result
        }

        // Option 1: Skip the current ride
        long long skipProfit = dfs(idx + 1, rides, memo);

        // Option 2: Take the current ride
        int start = rides[idx][0], end = rides[idx][1], tip = rides[idx][2];
        long long profit = end - start + tip;

        // Find the next non-overlapping ride
        int nextIdx = idx + 1;
        while (nextIdx < rides.size() && rides[nextIdx][0] < end) {
            nextIdx++;
        }
        long long takeProfit = profit + dfs(nextIdx, rides, memo);

        // Cache the result
        memo[idx] = max(skipProfit, takeProfit);
        return memo[idx];
    }

};