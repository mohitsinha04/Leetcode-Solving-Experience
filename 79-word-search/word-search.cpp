class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool res = false;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    res = res || dfs(board, word, i, j, 0);
                }
            }
        }
        return res;
    }
    
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int wordIndex) {
        if (wordIndex >= word.size()) return true;
        
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[wordIndex]) return false;
        
        char currChar = board[i][j];
        
        board[i][j] = '+';
        
        bool isTrue = dfs(board, word, i-1, j, wordIndex + 1) ||
            dfs(board, word, i+1, j, wordIndex + 1) ||
            dfs(board, word, i, j+1, wordIndex + 1) ||
            dfs(board, word, i, j-1, wordIndex + 1);
        
        board[i][j] = currChar;
        
        return isTrue;
    }
};