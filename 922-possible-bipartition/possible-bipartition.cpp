class Solution {
public:
    bool dfs(int index, int currColor, vector<vector<int>>& graph, vector<int>& color) {
        color[index] = currColor;

        for (auto i : graph[index]) {
            if (color[i] == -1) {
                if (!dfs(i, !currColor, graph, color)) return false;
            } else {
                if (color[i] == currColor) return false;
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);
        for (auto& dislike : dislikes) {
            adj[dislike[0]].push_back(dislike[1]);
            adj[dislike[1]].push_back(dislike[0]);
        }
        vector<int> color(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                if (!dfs(i, 0, adj, color))
                    return false;
            }
        }
        return true;
    }
};