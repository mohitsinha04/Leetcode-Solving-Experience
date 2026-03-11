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
            int currIndex = 0;
            while (currIndex < bucket[i].size() && res.size() < k) {
                res.push_back(bucket[i][currIndex]);
                currIndex++;
            }
        }
        return res;
    }
};

