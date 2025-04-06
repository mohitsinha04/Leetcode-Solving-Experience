class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int res = 0;

        for (int num : num_set) {
            if (!num_set.count(num - 1)) {
                int currNum = num;
                int streak = 1;
                while (num_set.count(currNum + 1)) {
                    currNum = currNum + 1;
                    streak++;
                }
                res = max(res, streak);
            }
        }
        return res;
    }
};