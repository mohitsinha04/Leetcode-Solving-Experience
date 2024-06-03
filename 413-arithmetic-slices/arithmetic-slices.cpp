class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        // vector<int> dp (nums.size(), 0);
        int dp = 0;
        int res = 0;
        // if (nums[2] - nums[1] == nums[1] - nums[0]) dp = 1;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                dp = dp + 1;
                res += dp;
            } else {
                dp = 0;
            }
            
        }
        return res;
    }
};

// [3,-1,-5,-9]
// 3 - -1 = 4;
// -1 - -5 = 4;
// -5 + 9 = 4;