class Solution {
public:
// https://leetcode.com/problems/single-threaded-cpu/solutions/7675163/c-min-heap-sort-on-log-n-simple-and-easy-532w/
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> temp;
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int n = tasks.size();

        // Preserve original indices
        for(int i = 0; i < n; i++){
            tasks[i].push_back(i);
        }

        sort(tasks.begin(), tasks.end());
        
        int i = 0;
        unsigned long t = tasks[0][0];

        while(!pq.empty() || i < n){
            // Load all arrived tasks into the queue
            while(i < n && t >= tasks[i][0]){
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }

            // Process the shortest task
            if(!pq.empty()){
                t += pq.top().first;
                temp.push_back(pq.top().second);
                pq.pop();
            } else {
                // TLE Bypass: Teleport clock to the next task's arrival time
                t = tasks[i][0];
            }
        }

        return temp;
    }
};