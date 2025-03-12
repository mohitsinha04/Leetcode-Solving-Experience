class Solution {
public:
    // [[0,30],[5,10],[15,20]]
    // [[5,10], [15,20], [0,30]]
    // [[0,30],[60,240],[90,120]]
    
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        // if (intervals.size() <= 1) return true;
        // auto cmp = [&] (const vector<int>& a, vector<int>& b) {
        //     return a[1] < b[1];
        // };
        
        // sort(intervals.begin(), intervals.end(), cmp);
        // int prev = intervals[0][1];
        
        // for (int i = 1; i < intervals.size(); i++) {
        //     if (prev > intervals[i][0]) return false;
        //     prev = intervals[i][1];
        // }
        // return true;
        map<int, int> line;
        
        for (auto interval : intervals) {
            line[interval[0]]++;
            line[interval[1]]--;
        }
        
        int res = 0;
        int count = 0;
        
        for (auto l : line) {
            count += l.second;
            if (count > 1) return false;
            res = max(res, count);
        }
        
        return res <= 1 ? true : false;
    }
};