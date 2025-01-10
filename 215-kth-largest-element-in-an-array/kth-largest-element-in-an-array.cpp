class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int minValue = INT_MAX;
        int maxValue = INT_MIN;
        
        for (int num: nums) {
            minValue = min(minValue, num);
            maxValue = max(maxValue, num);
        }
        vector<int> count(maxValue - minValue + 1);
        for (int num: nums) {
            count[num - minValue]++;
        }
        int remain = k;
        for (int i = count.size() - 1; i >= 0; i--) {
            remain -= count[i];
            if (remain <= 0) {
                return i + minValue;
            }
        }
        return -1;
    }
};