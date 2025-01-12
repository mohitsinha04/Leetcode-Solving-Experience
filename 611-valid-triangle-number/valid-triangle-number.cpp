class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size() - 2; i++) {
            int k = i + 2;
            for (int j = i + 1; j < nums.size() - 1 && nums[i] != 0; j++) {
                while (k < nums.size() && nums[i] + nums[j] > nums[k]) {
                    k++;
                }
                res += k - j - 1;
            }
        }
        return res;
    }
};