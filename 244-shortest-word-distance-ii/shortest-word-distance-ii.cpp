class WordDistance {
public:
    unordered_map<string, vector<int>> wordMap;

    WordDistance(vector<string>& wordsDict) {
        for (int i = 0; i < wordsDict.size(); i++) {
            string s = wordsDict[i];
            wordMap[s].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int> word1Array = wordMap[word1];
        vector<int> word2Array = wordMap[word2];

        int i =0, j = 0, res = INT_MAX;
        while (i < word1Array.size() && j < word2Array.size()) {
            res = min(res, abs(word1Array[i] - word2Array[j]));

            if (word1Array[i] < word2Array[j]) i++;
            else j++;
        }
        return res;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */