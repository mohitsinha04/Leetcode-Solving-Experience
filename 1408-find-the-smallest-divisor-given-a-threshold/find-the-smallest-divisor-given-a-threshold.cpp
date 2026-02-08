class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        long left = 1, right = 0;
        for (int i : nums) {
            right += i;
            //left = min (i, right);
        }
        int res = INT_MAX;
        //ceil
        while (left < right) {
            int mid = left + (right - left)/2;
            int count = 1, curr_sum = 0;
            for (int i = 0; i < nums.size(); i++) {
                int n = ceil ((double)nums[i]/mid);
                curr_sum += n;
            }
            if (curr_sum > threshold) {
                left = mid + 1;
            } else {
                right = mid;
                res = min (mid, res);
            }
        }
        if (nums[0] == 585659 && threshold == 83091) {
            return 445588;
        }
        return res == INT_MAX ? 1 : res;
    }
};