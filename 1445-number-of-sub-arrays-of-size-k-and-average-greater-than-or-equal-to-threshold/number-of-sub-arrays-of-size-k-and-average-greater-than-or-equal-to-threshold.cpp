class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
        int windowSum = 0;

        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        int count = 0;
        for (int i = 0; i < nums.size() - k + 1; i++) {
            if (i != 0) {
                windowSum -= nums[i-1];
                windowSum += nums[i + k - 1];
            }
            int windowAverage = windowSum / k;

            if (windowAverage >= threshold) count++;
        }
        return count;
    }
};