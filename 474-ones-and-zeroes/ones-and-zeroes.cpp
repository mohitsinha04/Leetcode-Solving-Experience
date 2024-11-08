class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m+1, vector<int>(n+1,-1)));
        return findMaxFormHelper(strs, m, n, 0, dp);
    }
    
    int findMaxFormHelper(vector<string>& strs, int zeroes, int ones, int i, 
                         vector<vector<vector<int>>>& dp) {
        if (i == strs.size()) return 0;
        
        vector<int> count = countZeroesOnes(strs[i]);
        
        if (dp[i][zeroes][ones] != -1) {
            return dp[i][zeroes][ones];
        }
        int taken = -1;
        if (zeroes >= count[0] && ones >= count[1]) {
            taken = 1 + findMaxFormHelper(strs, zeroes - count[0], ones - count[1], i + 1, dp);
        }
        int not_taken = findMaxFormHelper(strs, zeroes, ones, i + 1, dp);
        dp[i][zeroes][ones] = max(taken, not_taken);
        return dp[i][zeroes][ones];
    }
    vector<int> countZeroesOnes(string s) {
        vector<int> count(2, 0);
        for (int i = 0; i < s.size(); i++) {
            count[s[i]-'0']++;
        }
        return count;
    }
    
};

