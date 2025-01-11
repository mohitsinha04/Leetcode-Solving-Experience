class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        vector<int> map(2, 0);
        int winstart = 0, maxLength = 0;
        for (int winend = 0; winend < nums.size(); winend++) {
            map[nums[winend]]++;
            while (map[0] > k) {
                map[nums[winstart]]--;
                winstart++;
            }
            maxLength = max(maxLength, winend - winstart + 1);
        }
        return maxLength;
    }
};