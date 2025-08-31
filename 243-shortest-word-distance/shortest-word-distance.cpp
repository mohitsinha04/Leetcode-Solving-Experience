class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int lastWord1 = -1;
        int lastword2 = -1;

        int res = wordsDict.size();
        for (int i = 0; i < wordsDict.size(); i++) {
            if (wordsDict[i] == word1) {
                lastWord1 = i;
            } else if (wordsDict[i] == word2) {
                lastword2 = i;
            }
            if (lastWord1 != -1 && lastword2 != -1) {
                int currLen = abs(lastWord1 - lastword2);
                res = min(currLen, res);
            }
        }
        return res;
    }
};

// practice -> 0
// makes -> 1, 4
// perfect = 2
// coding = 3