class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> map(2051, 0);
        for (auto i : logs) {
            map[i[0]]++;
            map[i[1]]--;
        }
        
        int maxPopulation = 0;
        int maxPopIndex = -1;
        
        for (int i = 1950; i <= 2050; i++) {
            map[i] += map[i-1];
            
            if (map[i] > maxPopulation) {
                maxPopulation = map[i];
                maxPopIndex = i;
            }
        }
        return maxPopIndex;
    }
};