class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto cmp = [&](const vector<int>& a, const vector<int>& b){ 
            return a[1] < b[1];  
        };
        // [[1,2],[2,3],[3,4],[1,3]]
        // [[1,2],[1,3],[2,3],[3,4]]
        sort(intervals.begin(), intervals.end(), cmp);
        int prev = intervals[0][1];

        int res = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (prev > intervals[i][0]) {
                res++;
            } else {
                prev = intervals[i][1];
            }
        }
        return res;

    }
};