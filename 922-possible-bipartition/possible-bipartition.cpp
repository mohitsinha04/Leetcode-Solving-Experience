class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n + 1, 0);
        unordered_map<int, vector<int>> graph;
        queue<int> q;

        for (auto &edge: dislikes)
        {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int i = 1; i <= n; i++) {
            if (color[i]) continue;
            
            color[i] = 1;
            q.push(i);
            
            while (!q.empty()) {
                int temp = q.front();
                q.pop();
                
                for (auto neighbor : graph[temp]) {
                    if (color[neighbor] == 0){
                        color[neighbor] = -color[temp];
                        q.push(neighbor);
                    }
                    else if (color[neighbor] == color[temp]) 
                        return false;
                }
                
            }
        }
        return true;
    }
};