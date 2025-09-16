class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxpq, minpq;
        int maxLen = 0;
        int start = 0;


        for (int i = 0; i < nums.size(); i++) {
            while (!maxpq.empty() && maxpq.back() < nums[i]) {
                maxpq.pop_back();
            }
            
            maxpq.push_back(nums[i]);

            while (!minpq.empty() && minpq.back() > nums[i]) {
                minpq.pop_back();
            }
            minpq.push_back(nums[i]);

            while (maxpq.front() - minpq.front() > limit) {
                if (maxpq.front() == nums[start]) maxpq.pop_front();

                if (minpq.front() == nums[start]) minpq.pop_front();

                start++;
            }
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};