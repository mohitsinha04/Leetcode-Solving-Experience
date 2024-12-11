class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<vector<int>> maxHeap;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        
        int winstart = 0, maxLength = 0;
        
        for (int winend = 0; winend < nums.size(); winend++) {
            maxHeap.push({nums[winend], winend});
            minHeap.push({nums[winend], winend});
            
            while (maxHeap.top()[0] - minHeap.top()[0] > limit) {
                winstart = min(maxHeap.top()[1], minHeap.top()[1]) + 1;
                while (maxHeap.top()[1] < winstart) maxHeap.pop();
                while (minHeap.top()[1] < winstart) minHeap.pop();
            }
            maxLength = max(maxLength, winend - winstart + 1);
        }
        return maxLength;
    }
};