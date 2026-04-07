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

// 1, 0

// you must take 0 before 1;

//         0
//     1       2
//         3



// 1 -> 0;
// 2 -> 0;
// 3 -> 1, 2;

// indegree[1]++;
// indegree[2]++;
// indegree[3]+= 2;

// graph -> 
// 0 -> 1, 2;
// 1 -> 3;
// 2 -> 3;

// start from root which have the most dependecies, and then at the end process leaf