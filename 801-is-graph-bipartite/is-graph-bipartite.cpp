class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);

        for (int i = 0; i < graph.size(); i++) {
            if (color[i] == -1) {
                if (dfs(graph, color, i, 0) == false) return false;
            }
        }
        return true;
    }

    bool dfs(vector<vector<int>>& graph, vector<int>& color, int index, int currColor) {
        color[index] = currColor;

        for (auto i : graph[index]) {
            if (color[i] == -1) {
                if (!dfs(graph, color, i, !currColor)) return false;
            } else {
                if (color[i] == currColor) return false;
            }
        }
        return true;
    }
};