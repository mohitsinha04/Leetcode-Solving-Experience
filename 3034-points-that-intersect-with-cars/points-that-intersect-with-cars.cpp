class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        unordered_map<int, int> line;
        int minCord = INT_MAX;
        int maxCord = INT_MIN;
        for (auto num : nums) {
            line[num[0]]++;
            line[num[1]+1]--;
            minCord = min(minCord, num[0]);
            maxCord = max(maxCord, num[1]);
        }
        int count = 0;
        int res = 0;

        for (int i = minCord; i <= maxCord; i++) {
            count += line[i];
            if (count > 0) res++;
        }
        return res;
    }
};