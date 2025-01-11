class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        set<pair<int, int>> vis;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> minHeap;
        minHeap.push({nums1[0] + nums2[0], {0,0}});
        vis.insert({0,0});

        while (k-- && !minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();

            int i = top.second.first;
            int j = top.second.second;

            res.push_back({nums1[i], nums2[j]});

            if (i + 1 < nums1.size() && !vis.count({i+1, j})) {
                minHeap.push({nums1[i+1] + nums2[j], {i+1, j}});
                vis.insert({i + 1, j});
            } 
            if (j + 1 < nums2.size() && !vis.count({i, j + 1})) {
                minHeap.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                vis.insert({i, j + 1});
            }
        }
        return res;
    }
};