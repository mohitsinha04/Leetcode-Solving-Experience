class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        queue<int> q;
        vector<bool> seen(s.size(), false);
        q.push(0);

        while (!q.empty()) {
            int start = q.front();
            q.pop();

            if (start == s.size()) return true;

            for (int end = start + 1; end <= s.size(); end++) {
                if (seen[end]) continue;

                if (words.count(s.substr(start, end - start))) {
                    q.push(end);
                    seen[end] = true;
                }
            }
        }
        return false;
    }
};