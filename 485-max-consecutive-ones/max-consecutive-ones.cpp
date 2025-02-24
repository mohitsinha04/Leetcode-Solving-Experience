class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int res = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count += nums[i];
            } else {
                res = max(res, count);
                count = 0;
            }
        }
        return max(count, res);
    }
};