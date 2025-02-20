class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int curr = 0;
        int res = INT_MIN;
        for (int i : nums) {
            curr += i;
            res = max(res, curr);
            if (curr < 0) {
                curr = 0;
            }
        }
        return res;
    }
};