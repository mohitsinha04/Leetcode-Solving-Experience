class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> map;
        
        int res = 1;
        for (int i : arr) {
            if (!map.count(i - difference)) {
                map[i] = 1;
            } else {
                map[i] = map[i - difference] + 1;
            }
            res = max(res, map[i]);
        }
        return res;
    }
};