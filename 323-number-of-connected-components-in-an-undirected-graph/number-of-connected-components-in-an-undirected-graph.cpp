class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;

        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int res = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(graph, i, visited);
                res++;
            }
        }
        return res;
    }

    void dfs(unordered_map<int, vector<int>>& graph, int source, vector<bool>& vis) {
        vis[source] = true;
        for (int i : graph[source]) {
            if (vis[i]) continue;
            dfs(graph, i, vis);
        }
    }
};