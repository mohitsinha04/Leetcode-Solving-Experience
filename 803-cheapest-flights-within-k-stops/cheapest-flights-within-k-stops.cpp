class Solution {
public:
// flights[i] = [fromi, toi, pricei]
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto edge : flights) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        vector<int> stops(n, INT_MAX);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int currdist = curr[0];
            int node = curr[1];
            int steps = curr[2];
            // we are using pq, thats why minimum steps would give us ans
            if (steps > stops[node] || steps > k + 1) continue;
            stops[node] = steps;
            if (node == dst) return currdist;
            for (auto& [neighbor, price] : adj[node]) {
                pq.push({currdist + price, neighbor, steps + 1});
            }
        }
        return -1;
    }
};