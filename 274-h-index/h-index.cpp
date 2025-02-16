class Solution {
public:
// https://www.youtube.com/watch?v=mgG5KFTvfPw
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> counter(n + 1, 0);
        int currSum = 0;
        for(int c : citations) {
            if (c >= n) counter[n]++;
            else counter[c]++;
        }
        for (int i = n; i >= 0; i--) {
            currSum += counter[i];
            if (currSum >= i) return i;
        }
        return 0;
    }
};