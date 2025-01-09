class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        if (nums.size() == 1) return 1;

        int maxBeauty = 0;
        int maxValue = 0;

        for (int i : nums) maxValue = max(maxValue, i);

        vector<int> lineSweep (maxValue + 1, 0);

        for (int num : nums) {
            lineSweep [max(num - k, 0)]++;
            if (num + k + 1 <= maxValue) {
                lineSweep [num + k + 1]--;
            }
        }

        int currSum = 0;
        for (int val : lineSweep) {
            currSum += val;
            maxBeauty = max(maxBeauty, currSum);
        }
        return maxBeauty;
    }
};