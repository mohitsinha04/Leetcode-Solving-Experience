class Solution {
public:
    int rob(vector<int>& nums) {
        // if ()
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[1], nums[0]);
        return max(helper(nums, 0, nums.size() - 1), helper(nums, 1, nums.size()));
    }
    int helper(vector<int> nums, int start, int end) {
        int dp2 = nums[start];
        // if (end)
        int dp1 = max(nums[start], nums[start + 1]);
        int res = dp1;
        
        for (int i = start + 2; i < end; i++) {
            res = max(dp1, dp2 + nums[i]);
            dp2 = dp1;
            dp1 = res;
        }
        return res;
    }
};


// [1,2,3,1];
