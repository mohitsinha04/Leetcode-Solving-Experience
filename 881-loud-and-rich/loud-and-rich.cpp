class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        unordered_map<int, vector<int>> graph;
        
        for (int i = 0; i < quiet.size(); i++) graph[i] = {};
        
        for (auto rich : richer) {
            graph[rich[1]].push_back(rich[0]);
        }
        
        vector<int> res(quiet.size(), -1);
        
        for (int i = 0; i < res.size(); i++) {
            dfs(graph, quiet, res, i);
        }
        return res;
    }
    
    int dfs(unordered_map<int, vector<int>>& graph, vector<int>& quiet, vector<int>& res, int source) {
        if (res[source] == -1) {
            res[source] = source;
            for (int child : graph[source]) {
                int candidate = dfs(graph, quiet, res, child);
                if (quiet[candidate] < quiet[res[source]]) 
                    res[source] = candidate;
            }
        }
        return res[source];
    }
};


// [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]]


//                                 0 (5)
            
//                 1 (5)                          7  (7)       

//     2 (2)                   3 (5)
            
//            4(4)             5 (5)          6 (6)
