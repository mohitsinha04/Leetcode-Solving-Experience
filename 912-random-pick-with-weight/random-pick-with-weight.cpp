class Solution {
public:
// https://www.youtube.com/watch?v=fWS0TCcr-lE
// https://leetcode.com/problems/random-pick-with-weight/solutions/671487/easy-understood-java-solution-with-cumulative-sum-and-binary-search

    vector<int> cumSum;
    int n;
    Solution(vector<int>& w) {
        cumSum.resize(w.size());
        cumSum[0] = w[0];
        n = w.size();
        for (int i = 1; i < w.size(); i++) {
            cumSum[i] = cumSum[i-1] + w[i];
        }
    }

    int search(int left, int right, int p) {
        int mid = (right + left) /2;
        if (cumSum[mid] < p) return search(mid + 1, right, p);
        else if (mid == left) return mid;
        return search(left, mid, p);
    }
    
    int pickIndex() {
        int p = rand() % cumSum[n - 1] + 1;
        return search(0, n -1, p);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */