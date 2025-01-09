class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> nums_map(102, 0);

        for (auto i : nums) {
            nums_map[i[0]]++;
            nums_map[i[1]+1]--;
        }
        int total_car = 0, res = 0;
        for (int i = 1; i < 101; i++) {
            total_car += nums_map[i];
            if (total_car > 0) res++;
        }
        return res;
    }
};