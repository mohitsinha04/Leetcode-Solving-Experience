class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size());

        for (int i = 0; i < s.size(); i++) {
            for (string word : wordDict) {

                if (i < word.size() - 1) continue;

                if (i == word.size() - 1 || dp[i- word.size()]) {
                    if (s.substr(i - word.size() + 1, word.size()) == word) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size() - 1];
    }
};