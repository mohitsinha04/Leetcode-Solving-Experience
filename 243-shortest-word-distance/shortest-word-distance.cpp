class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int lastword1 = -1;
        int lastword2 = -1;
        int res = wordsDict.size();
        for (int i = 0; i < wordsDict.size(); i++) {
            if (wordsDict[i] == word1) {
                lastword1 = i;
            } else if (wordsDict[i] == word2) {
                lastword2 = i;
            } 
            if (lastword1 != -1 && lastword2 != -1) {
                int currDist = abs(lastword1 - lastword2);
                res = min(res, currDist);
            }
        }
        return res;
    }
};