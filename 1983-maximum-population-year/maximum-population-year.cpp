class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        unordered_map<int, int> line;
        int minYear = INT_MAX;
        int maxYear = INT_MIN;
        for (auto log : logs) {
            line[log[0]]++;
            line[log[1]]--;
            minYear = min(minYear, log[0]);
            maxYear = max(maxYear, log[1]);
        }
        int res = 0;
        int count = 0;
        int resYear = -1;
        for (int i = minYear; i <= maxYear; i++) {
            count += line[i];
            if (count > res) {
                res = count;
                resYear = i;
            }
        }
        return resYear;
    }
};