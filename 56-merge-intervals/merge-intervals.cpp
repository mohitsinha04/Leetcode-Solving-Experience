class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int start = intervals[0][0];
        int end = intervals[0][1];
        vector<vector<int>> res;
        for (int i = 1; i < intervals.size(); i++) {
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            if (currStart <= end) {
                end = max(end, currEnd);
            } else {
                res.push_back({start, end});
                start = currStart;
                end = currEnd;
            }
        }
        res.push_back({start, end});
        return res;

    }
};