class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        vector<int> inDegree(n, 0);
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            inDegree[edge[0]]++;
            inDegree[edge[1]]++;
        }
        queue<int> q;
        unordered_set<int> vis;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 1) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();
                vis.insert(curr);
                // inDegree[curr]--;
                for (int adj : graph[curr]) {
                    if (--inDegree[adj] == 1) {
                        q.push(adj);
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (inDegree[i] > 1) return false;
        }
        return edges.size() == n-1;
    }
};