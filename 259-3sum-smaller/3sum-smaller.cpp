class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        for (int k = 2; k < n; ++k) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] < target - nums[k]) {
                    ans += j - i;
                    i += 1;
                } else {
                    j -= 1;
                }
            }
        }
        return ans;
    }
};