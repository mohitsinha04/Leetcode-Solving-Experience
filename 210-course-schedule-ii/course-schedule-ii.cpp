class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> inDegree(numCourses, 0);

        for (auto pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) q.push(i);
        }
        vector<int> res;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            res.push_back(curr);

            for (auto adj : graph[curr]) {
                if (--inDegree[adj] == 0) {
                    q.push(adj);
                }
            }
        }
        if (res.size() == numCourses) return res;
        return {};
    }
};