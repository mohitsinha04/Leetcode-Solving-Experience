class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> population_year(2051, 0);
        for (auto i : logs) {
            population_year[i[0]]++;
            population_year[i[1]]--;
        }
        
        int maxPopulation = 0;
        int maxPopIndex = -1;
        
        for (int i = 1950; i <= 2050; i++) {
            population_year[i] += population_year[i-1];
            
            if (population_year[i] > maxPopulation) {
                maxPopulation = population_year[i];
                maxPopIndex = i;
            }
        }
        return maxPopIndex;
    }
};