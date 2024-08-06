class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<vector<int>> dp(books.size(), vector<int> (shelfWidth + 1, -1));
        return helper(books, shelfWidth, dp, 0, shelfWidth, 0);
    }
    int helper(vector<vector<int>>& books, int shelfWidth, vector<vector<int>>& dp,
              int i, int remainingshelfWidth, int maxHeight) {
        vector<int> currBook = books[i];
        int curr_height = max(maxHeight, currBook[1]);
        if (i == books.size() -1) {
            if (remainingshelfWidth >= currBook[0]) return curr_height;
            return maxHeight + currBook[1];
        } 
        if (dp[i][remainingshelfWidth] != -1) return dp[i][remainingshelfWidth];
        
        int newHeight = maxHeight + helper(books, shelfWidth, dp, i + 1, 
                                       shelfWidth - currBook[0], currBook[1]);
        if (remainingshelfWidth >= currBook[0]) {
            int currHeight = helper(books, shelfWidth, dp, i + 1, 
                               remainingshelfWidth - currBook[0], curr_height);
            return dp[i][remainingshelfWidth] = min(newHeight, currHeight);
        }
        return dp[i][remainingshelfWidth] = newHeight;
    }
};
// [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]]