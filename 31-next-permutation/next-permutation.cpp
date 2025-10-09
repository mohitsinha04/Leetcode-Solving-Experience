class Solution {
public:
    // 2, 1, 5, 4, 3, 0, 0;
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 0) return;
        int i = nums.size() - 2;
        while (i >= 0 && nums[i+1] <= nums[i]) {
            i--;
        }
        
        // cout << i << endl;
            
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j > i && nums[i] >= nums[j]) j--;
            // cout << j << endl;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};