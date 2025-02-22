class Solution {
public:

    int find(int r, vector<int>& parent) {
        int p = parent[r];
        if (r != parent[r]) {
            parent[r] = find(parent[r], parent);
        }
        return parent[r];
    }

    bool unionEdges(int source, int dest, vector<int>& parent, vector<int>& size) {
        int p1 = find(source, parent);
        int p2 = find(dest, parent);

        if (p1 == p2) {
            return false;
        } else {
            if (size[p1] > size[p2]) {
                size[p1] += size[p2];
                parent[p2] = p1;
            } else {
                size[p2] += size[p1];
                parent[p1] = p2;
            }
            return true;
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<int> parent(n), size(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }

        for (auto edge : edges) {
            int a = edge[0];
            int b = edge[1];
            if (!unionEdges(a, b, parent, size)) return false;
        }

        return true;
    }
};