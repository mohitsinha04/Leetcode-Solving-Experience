class Solution {
public:
    int n;
    vector<vector<int>> memo;

    int minSteps(int n) {
        if (n == 1) return 0;
        this->n = n;
// The dimensions of memo can be (n+1)×(n/2+1), because the current number of characters is at most n and the previous copy length is at most n/2
        memo = vector<vector<int>>(n + 1, vector<int>(n / 2 + 1, 0));
        return 1 + minStepsHelper(1, 1);
    }

    int minStepsHelper(int currLen, int pasteLen) {
        if (currLen == n) return 0;
        if (currLen > n) return 1000;

        // return result if it has been calculated already
        if (memo[currLen][pasteLen] != 0) return memo[currLen][pasteLen];

        int opt1 = 1 + minStepsHelper(currLen + pasteLen, pasteLen);
        int opt2 = 2 + minStepsHelper(currLen * 2, currLen);
        memo[currLen][pasteLen] = min(opt1, opt2);
        return memo[currLen][pasteLen];
    }
};