class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, leftsum = 0;
        for (int i : nums) sum += i;

        for (int i = 0; i < nums.size(); i++) {
            if (leftsum == sum - leftsum - nums[i]) return i;
            leftsum += nums[i];
        }
        return -1;
    }
};