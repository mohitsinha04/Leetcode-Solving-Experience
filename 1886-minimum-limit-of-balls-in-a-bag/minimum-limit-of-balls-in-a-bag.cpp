class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1;
        int right = INT_MIN;
        long totalSum = 0;
        for (int i : nums) {
            right = max(right, i);
            totalSum += i;
            // if (totalSum < maxOperations) return 1;
        }
        // i

        int res = INT_MAX;
        while (left < right) {
            int mid = left + (right - left)/2;
            if (eligible (mid, nums, maxOperations)) {
                res = min(res, mid);
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    bool eligible (int mid, vector<int>& nums, int maxOps) {
        int currOps = 0;
        for (int i = 0; i < nums.size(); i++) {
                int curr = ceil(nums[i]/(double)mid) -1;
                currOps += curr;
                if (currOps > maxOps) return false;
        }
        return true;
    }
};