class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<array<int, 3>> times;
        for (auto event : events) {
            times.push_back({event[0], 1, event[2]});
            times.push_back({event[1] + 1, 0, event[2]});
        }
        int res = 0, maxValue = 0;
        sort(times.begin(), times.end());

        for (auto time : times) {
            if (time[1]) {
                res = max(res, time[2] + maxValue);
            } else {
                maxValue = max(maxValue, time[2]);
            }
        }
        return res;
    }
};