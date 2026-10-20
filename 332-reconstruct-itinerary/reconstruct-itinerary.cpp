class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> graph;
        stack<string> dfs;
        for(auto i : tickets) 
            graph[i[0]].insert(i[1]);
        vector<string> res;
        dfs.push("JFK");
        while(!dfs.empty()) {
            string curr = dfs.top();
            if(graph[curr].empty()) {
                res.push_back(curr);
                dfs.pop();
            } else {
                dfs.push(*graph[curr].begin());
                graph[curr].erase(graph[curr].begin());
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};