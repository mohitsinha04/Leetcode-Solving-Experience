class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int sec = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            if (first >= nums[i]) {
                first = nums[i];
            } else if (sec >= nums[i]) {
                sec = nums[i];
            } else return true;
        }
        return false;
    }
};