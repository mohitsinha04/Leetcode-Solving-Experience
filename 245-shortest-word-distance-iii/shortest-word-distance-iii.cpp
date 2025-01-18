class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int res = INT_MAX;

        int prev = -1;

        for (int i = 0; i < wordsDict.size(); i++) {
            if (wordsDict[i] == word1 || wordsDict[i] == word2) {
                if (prev != -1 && (wordsDict[prev] != wordsDict[i] || word1 == word2)) {
                    res = min (res, i - prev);
                }
                prev = i;
            }
        }
        return res;
    }
};
