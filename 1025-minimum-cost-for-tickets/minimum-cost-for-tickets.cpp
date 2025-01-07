class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastDay = days[days.size() - 1];
        vector<int> dp(lastDay + 1, -1);

        unordered_set<int> days_set(days.begin(), days.end());

        return solve(days_set, days, costs, dp, 1);
    }

    int solve (unordered_set<int> days_set, vector<int>& days, vector<int>& costs, vector<int>& dp, int currDay) {
        if (currDay > days[days.size()-1]) 
            return 0;
        if (!days_set.count(currDay)) {
            return solve(days_set, days, costs, dp, currDay + 1);
        }
        if (dp[currDay] != -1) return dp[currDay];

        int day1 = costs[0] + solve(days_set, days, costs, dp, currDay + 1);
        int day7 = costs[1] + solve(days_set, days, costs, dp, currDay + 7);
        int day30 = costs[2] + solve(days_set, days, costs, dp, currDay + 30);

        return dp[currDay] = min(day1, min(day7, day30));

    }
};