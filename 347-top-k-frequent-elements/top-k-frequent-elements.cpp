class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numsFreq;
        for (int i : nums) numsFreq[i]++;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        for (auto i : numsFreq) {
            pq.push({i.second, i.first});
            if (pq.size() > k) pq.pop();
            
        }
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top()[1]);
            pq.pop();
        }
        return res;
    }
};