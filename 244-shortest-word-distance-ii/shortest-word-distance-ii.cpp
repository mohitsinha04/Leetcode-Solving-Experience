class WordDistance {
public:
    vector<string> wordsDict;
    unordered_map<string, vector<int>> wordsIndex;
    WordDistance(vector<string>& wordsDict) {
        this->wordsDict = wordsDict;

        for (int i = 0; i < wordsDict.size(); i++) {
            wordsIndex[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int> word1Indices = wordsIndex[word1];
        vector<int> word2Indices = wordsIndex[word2];

        int i = 0, j = 0;
        int res = wordsDict.size();
        while (i < word1Indices.size() && j < word2Indices.size()) {
            int curr = abs(word1Indices[i] - word2Indices[j]);
            res = min(res, curr);

            if (word1Indices[i] < word2Indices[j]) {
                i++;
            } else j++;
        }
        return res;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */



// practice -> 0
// makes -> 1, 4
// perfect = 2
// coding = 3