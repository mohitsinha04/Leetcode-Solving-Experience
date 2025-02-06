class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] > nums[nums.size() - 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        int start = left;
        if (nums[start] <= target && nums[nums.size() - 1] >= target) {
            left = start;
            right = nums.size() - 1;
        } else {
            left = 0;
            right = start - 1;
        }

        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
};