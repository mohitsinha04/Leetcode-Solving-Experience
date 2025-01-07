class Solution {
public:
    vector<int> parent;
    vector<int> ranks;

    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());
        parent.resize(n, 0);
        ranks.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (auto log : logs) {
            if (find(log[1]) == find(log[2])) 
                continue;

            combine(log[1], log[2]);
            if (ranks[parent[log[1]]] == n || ranks[parent[log[2]]] == n) return log[0];
        }
        return -1;
    }
    int find(int v) {
        if(parent[v] != v) {
            parent[v] = find(parent[v]);
        }
        return parent[v];
    }


    void combine(int u, int v) {
        int pu = find(v);
        int pv = find(u);
        if(ranks[pu] > ranks[pv]) {
            parent[pv] = pu;
            ranks[pu] += ranks[pv];
        } else if(ranks[pu] < ranks[pv]) {
            parent[pu] = pv;
            ranks[pv] += ranks[pu];
        } else {
            parent[pu] = pv;
            ranks[pv] += ranks[pu];
        }
    }

};