class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        queue<string> q;
        q.push(beginWord);
        
        if (wordSet.count(beginWord)) wordSet.erase(beginWord);
        
        int level = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string curr = q.front();
                q.pop();

                if (curr == endWord) return level;

                for (int i = 0; i < curr.size(); i++) {
                    char currChar = curr[i];
                    for (int j = 0; j < 26; j++) {
                        curr[i] = 'a' + j;
                        if (curr[i] != currChar && wordSet.count(curr)) {
                            q.push(curr);
                            wordSet.erase(curr);
                        }
                    }
                    curr[i] = currChar;
                }
            }
            level++;
        }
        return 0;
    }
};