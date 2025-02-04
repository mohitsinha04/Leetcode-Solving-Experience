class Solution {
public:
    vector<pair<int, int>> adj[101];
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for (auto time : times) {
            int src = time[0];
            int dest = time[1];
            int weight = time[2];

            adj[src].push_back({weight, dest});
        }

        vector<int> dist(n + 1, INT_MAX);
        dijkstra(dist, k, n);
        int res = INT_MIN;
        for (int i = 1; i <= n; i++) {
            res = max(res, dist[i]);
        }

        return res == INT_MAX ? -1 : res;
    }

    void dijkstra(vector<int>& dist, int src, int n) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});

        dist[src] = 0;

        while (!pq.empty()) {
            int currWeight = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            if (currWeight > dist[currNode]) continue;

            for (auto e : adj[currNode]) {
                int time = e.first;
                int neighbor = e.second;

                if (dist[neighbor] > currWeight + time) {
                    dist[neighbor] = currWeight + time;
                    pq.push({dist[neighbor], neighbor});
                }
            }
        }
    }

};