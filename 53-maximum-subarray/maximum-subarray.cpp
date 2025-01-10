class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0, res = INT_MIN;
        for (int num : nums) {
            currSum += num;
            res = max(res, currSum);
            if (currSum < 0) {
                currSum = 0;
            }
        }
        return res == INT_MIN ? -1 : res;
    }
};