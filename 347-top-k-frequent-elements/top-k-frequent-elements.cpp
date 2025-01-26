class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> bucket(nums.size() + 1);
        unordered_map<int, int> freqMap;

        for (int num : nums) {
            freqMap[num]++;
        }

        for (auto i : freqMap) {
            int freq = i.second;
            bucket[i.second].push_back(i.first);
        }
        vector<int> res;

        for (int i = nums.size(); i>= 0 && res.size() < k; i--) {
            if (!bucket[i].empty()) {
                res.insert(res.end(), bucket[i].begin(), bucket[i].end());
            }
        }
        return res;
    }
};