class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() && res != 0; i++) {
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(target - sum) < abs(res)) {
                    res = target - sum;
                }
                if (sum < target) left++;
                else right--;
            }
        }
        return target - res;
    }
};