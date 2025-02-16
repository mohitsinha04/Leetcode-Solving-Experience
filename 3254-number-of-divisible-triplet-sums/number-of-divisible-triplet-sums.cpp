class Solution {
public:
    int divisibleTripletCount(vector<int>& A, int d) {
        int res = 0;
        int n = A.size();
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> seen;
            for (int j = i + 1; j < n; j++) {
                res += seen[(d - A[j] % d) % d];
                seen[(A[i] + A[j]) % d]++;
            }
        }
        return res;
    }
};