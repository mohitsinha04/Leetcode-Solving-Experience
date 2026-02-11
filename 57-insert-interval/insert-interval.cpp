class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        map<int, int> line;

        for (auto interval : intervals) {
            line[interval[0]]++;
            line[interval[1]]--;
        }
        line[newInterval[0]]++;
        line[newInterval[1]]--;

        int count = 0, start = 0;
        vector<vector<int>> res;
        for (auto l : line) {
            if (count == 0) {
                start = l.first;
            }
            count += l.second;
            if (count == 0) {
                res.push_back({start, l.first});
            }
        }
        return res;
    }
};