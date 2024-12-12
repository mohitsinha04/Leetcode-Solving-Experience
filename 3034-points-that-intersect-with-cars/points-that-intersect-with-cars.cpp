class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> cars(102, 0);
        for (auto i : nums) {
            cars[i[0]]++;
            cars[i[1] + 1]--;
        }
        
        int res = 0;
        
        for (int i = 1; i <= 101; i++) {
            cars[i] += cars[i-1];
            if (cars[i] > 0) {
                res ++;
            }
            
        }
        return res;
    }
};