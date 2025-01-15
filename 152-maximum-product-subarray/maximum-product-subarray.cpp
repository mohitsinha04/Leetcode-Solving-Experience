class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int maxSoFar = nums[0];
        int minSoFar = nums[0];
        int res = maxSoFar;

        for (int i = 1; i < nums.size(); i++) {
            int temp = max(nums[i], max(nums[i] * maxSoFar, nums[i] * minSoFar));
            minSoFar = min(nums[i], min(nums[i] * minSoFar, nums[i] * maxSoFar));
            maxSoFar = temp;
            res = max(res, maxSoFar);
        }
        return res;
    }
};