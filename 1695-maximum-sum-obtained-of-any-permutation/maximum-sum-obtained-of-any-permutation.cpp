class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        vector<int> aux(nums.size(), 0);
        for (auto request : requests) {
            aux[request[0]]++;

            if (request[1] != nums.size() - 1) aux[request[1] + 1]--;
        }

        for (int i = 1; i < aux.size(); i++) {
            aux[i] += aux[i-1];
        }
        sort(aux.begin(), aux.end());
        sort(nums.begin(), nums.end());

        int res = 0, mod = 1e9 + 7;
        for (int i = 0; i < aux.size(); i++) {
            res = (res + 1LL * nums[i] * aux[i]) % mod;
        }
        return res;
    }
};

// ans = (ans + (nums[i] * t[i])) % mod;
