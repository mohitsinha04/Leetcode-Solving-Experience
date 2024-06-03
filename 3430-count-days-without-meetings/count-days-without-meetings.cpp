class Solution {
public:
    
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        
        int i = 0;
        int res = 0;
        if (meetings[0][0] > 1) {
            res += abs(meetings[0][0] - 1);
        }
       
        for (i = 0; i < meetings.size() - 1; i++) {
            if (meetings[i+1][0] <= meetings[i][1]) {
                if (meetings[i][1] > meetings[i+1][1]) meetings[i+1][1] = meetings[i][1];
            }
            if (meetings[i][1] < meetings[i+1][0]) {
                res += meetings[i+1][0] - meetings[i][1] - 1;
            }
        }
        if (meetings[i][1] < days) {
            res += abs(days - meetings[i][1]);
        }
        
        return res;
    }
};
// [[1, 3], [5,7], [9,10]]
// 4, 8;

// [1,3] [2, 4];

