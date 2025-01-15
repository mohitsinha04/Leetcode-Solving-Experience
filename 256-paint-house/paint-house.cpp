class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.size() == 0) return 0;
        vector<int> prev = costs[costs.size() - 1];

        for (int i = costs.size() - 2; i >= 0; i--) {
            vector<int> curr = costs[i];
            curr[0] += min(prev[1], prev[2]);
            curr[1] += min(prev[0], prev[2]);
            curr[2] += min(prev[1], prev[0]);
            prev = curr;
        }
        return min(prev[0], min(prev[1], prev[2]));
    }
};