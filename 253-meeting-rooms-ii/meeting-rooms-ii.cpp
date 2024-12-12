class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> line;
        
        for (auto interval : intervals) {
            line[interval[0]]++;
            line[interval[1]]--;
        }
        
        int res = 0;
        int count = 0;
        
        for (auto l : line) {
            count += l.second;
            res = max(res, count);
        }
        
        return res;
        
    }
};