class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });

        int prev = INT_MIN, res = 0;
        for (auto p : pairs) {
            if (p[0] > prev) {
                res++;
                prev = p[1];
            }
        }
        return res;
    }
};