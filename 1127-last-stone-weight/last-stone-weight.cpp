class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.size() <= 0) return 0;
        priority_queue<int> maxHeap;

        for (int i : stones) {
            maxHeap.push(i);
        }

        while (maxHeap.size() > 1) {
            int first = maxHeap.top();
            maxHeap.pop();
            int second = maxHeap.top();
            maxHeap.pop();
            maxHeap.push(first - second);
        }
        return maxHeap.top();
    }
};