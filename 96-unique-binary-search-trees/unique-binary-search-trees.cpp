class Solution {
public:
    int numTrees(int n) {
        vector<int> bst(n + 1, 0);
        bst[0] = bst[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                bst[i] += bst[j-1] * bst[i-j];
            }
        }
        return bst[n];
    }
};