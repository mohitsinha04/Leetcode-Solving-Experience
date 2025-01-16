class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int res = 0;
        int prod = 1;

        int winstart = 0;
        for (int winend = 0; winend < nums.size(); winend++) {
            prod = prod * nums[winend];

            while (prod >= k) {
                prod = prod / nums[winstart];
                winstart++;
            }
            res += winend - winstart + 1;
        }
        return res;
    }
};