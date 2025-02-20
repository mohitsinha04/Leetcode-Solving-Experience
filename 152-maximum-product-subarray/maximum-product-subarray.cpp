class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int maxProd = nums[0];
        int minProd = nums[0];

        int res = maxProd;

        for (int i = 1; i < nums.size(); i++) {
            int temp = max(nums[i], max(nums[i] * maxProd, nums[i] * minProd));
            minProd = min(nums[i], min(nums[i] * maxProd, nums[i] * minProd));
            maxProd = temp;
            res = max(res, maxProd);
        }
        return res;
    }
};