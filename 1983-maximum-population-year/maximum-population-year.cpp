class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> population_year(2051, 0);
        int earliestYear = INT_MAX, oldestYear = INT_MIN;
        for (auto i : logs) {
            population_year[i[0]]++;
            population_year[i[1]]--;
            earliestYear = min(i[0], earliestYear);
            oldestYear = max(i[1], oldestYear);
        }
        
        int maxPopulation = 0;
        int maxPopIndex = -1;
        
        for (int i = earliestYear; i <= oldestYear; i++) {
            population_year[i] += population_year[i-1];
            
            if (population_year[i] > maxPopulation) {
                maxPopulation = population_year[i];
                maxPopIndex = i;
            }
        }
        return maxPopIndex;
    }
};