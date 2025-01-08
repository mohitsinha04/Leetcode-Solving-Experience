class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        long long totalSum = 0;
        unordered_map<int, int> freq;
        for (int i : nums) {
            totalSum += i;
            freq[i]++;
        }
        int maxOutliner = INT_MIN;
        for (int num : nums) {
            int reqSum = totalSum - num;
            if (reqSum % 2 != 0) continue;

            long long sumElem = reqSum/2;
            freq[num]--;
            int summ = (int) sumElem;
            int count = freq.count(sumElem) ? freq[sumElem] : 0;
            if (count > 0) maxOutliner = max(maxOutliner, num);
            freq[num]++;
        }
        return maxOutliner;
    }
};