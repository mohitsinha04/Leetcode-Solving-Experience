class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });

        int prev = INT_MIN, res = 0;
        for (auto interval : intervals) {
            if (prev > interval[0]) {
                res++;
            } else {
                prev = interval[1];
            }
        }
        return res;
    }
};