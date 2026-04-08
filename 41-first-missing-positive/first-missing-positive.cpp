class Solution {
public:
// [1,2,0]
// nums[0] = 1;
// nums[1-1] = nums[0] = 1;

// [3,4,-1,1];
// nums[3-1] = nums[2] = -1;
// [-1,4,3,1]
// nums[3] = 1;
// [-1,1,3,4]
// nums[1-1] = nums[0] = -1
// 1,-1,3,4;



    int firstMissingPositive(vector<int>& nums) {
        int position = 0;

        int i = 0;
        while (i < nums.size()) {
            if (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            } 
            else i++;
        }

        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != j + 1) 
                return j + 1;
        }
        return nums.size() + 1;
    }
};