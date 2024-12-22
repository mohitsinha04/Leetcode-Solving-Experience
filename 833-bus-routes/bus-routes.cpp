class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        if (source == target) {
            return 0;
        }
        
        unordered_map<int, vector<int>> graph;
        
        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i]) {
                graph[stop].push_back(i);
            }
        }
        
        queue<int> q;
        unordered_set<int> vis;
        
        for (int r : graph[source]) {
            q.push(r);
            vis.insert(r);
        }
        
        int level = 1;
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();
                
                for (int stop : routes[curr]) {
                    if (stop == target) return level;
                    
                    for (int r : graph[stop]) {
                        if (!vis.count(r)) {
                            q.push(r);
                            vis.insert(r);
                        } 
                    }  
                }
            }
            level++;
        }
        return -1;
    }
};