class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> adjList;
        unordered_map<char, int> indegree;
        for (string word : words) {
            for (char c : word) {
                indegree[c] = 0;
                adjList[c] = vector<char>();
            }
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i];
            string word2 = words[i + 1];

            if (word1.size() > word2.size() && word1.substr(0, word2.size()) == word2) {
                return "";
            }

            for (int j = 0; j < min(word1.size(), word2.size()); j++) {
                if (word1[j] != word2[j]) {
                    adjList[word1[j]].push_back(word2[j]);
                    indegree[word2[j]]++;
                    break;
                }
            }
        }

        string res = "";
        queue<char> q;
        for (auto item : indegree) {
            if (item.second == 0) q.push(item.first);
        }

        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            res += curr;
            for (char next : adjList[curr]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        if (res.size() < indegree.size()) {
            return "";
        }
        return res;

    }
};