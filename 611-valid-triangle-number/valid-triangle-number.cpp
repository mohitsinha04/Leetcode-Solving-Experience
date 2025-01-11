class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res = 0;
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            int k = i + 2;
            for (int j = i + 1; j < nums.size() - 1 && nums[i] != 0; j++) {
                k = bs(nums, k, nums.size() - 1, nums[i] + nums[j]);
                res += k - j - 1;
            }
        }
        return res;
    }
    int bs(vector<int>& nums, int left, int right, int target) {
        while (left <= right && right < nums.size()) {
            int mid = left + (right - left)/2;
            if (nums[mid] >= target) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};