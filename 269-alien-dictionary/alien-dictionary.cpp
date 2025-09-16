class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, int> indegree;
        unordered_map<char, vector<int>> adjMat;

        for (auto word : words) {
            for (auto c : word) {
                indegree[c] = 0;
                adjMat[c] = {};
            }
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i];
            string word2 = words[i+1];

            if (word1.size() > word2.size() && word1.substr(0, word2.size()) == word2) {
                return "";
            }

            for (int j = 0; j < min(word1.size(), word2.size()); j++) {
                if (word1[j] != word2[j]) {
                    adjMat[word1[j]].push_back(word2[j]);
                    indegree[word2[j]]++;
                    break;
                }
            }
        }
        queue<char> q;
        for (auto in : indegree) {
            if (in.second == 0) {
                q.push(in.first);
            }
        }
        string res = "";
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            res += curr;

            for (auto neighbour : adjMat[curr]) {
                if (--indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }
        for (auto in : indegree) {
            if (in.second != 0) return "";
        }
        return res;
    }
};