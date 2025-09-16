class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        unordered_map<int, vector<int>> routeGraph;

        for (int i = 0; i < routes.size(); i++) {
            for (auto r : routes[i]) {
                routeGraph[r].push_back(i);
            }
        }
        
        unordered_set<int> vis;
        queue<int> q;

        for (auto s : routeGraph[source]) {
            q.push(s);
            vis.insert(s);
        }

        int level = 1;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();
                
                for (int stop : routes[curr]) {
                    if (stop == target) return level;
                    
                    for (int r : routeGraph[stop]) {
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