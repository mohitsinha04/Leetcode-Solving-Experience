class Solution {
public:
    int getLiveNeighbours(vector<vector<int>>& curr, int i, int j, int m, int n) {
        int liveNeighbours = 0;
        if(i>0) {
            //check the upper neighbour
            if(curr[i-1][j] == 1 || curr[i-1][j] == 3) liveNeighbours++;
        }
        if(i<m-1) {
            //check the lower neighbour
            if(curr[i+1][j] == 1 || curr[i+1][j] == 3) liveNeighbours++;
        }
        if(j>0) {
            //check the left neighbour
            if(curr[i][j-1] == 1 || curr[i][j-1] == 3) liveNeighbours++;
        }
        if(j<n-1) {
            //check the right neighbour
            if(curr[i][j+1] == 1 || curr[i][j+1] == 3) liveNeighbours++;
        }
        // diagonals
        if(i>0 && j>0) {
            if(curr[i-1][j-1] == 1 || curr[i-1][j-1] == 3) liveNeighbours++;
        }
        if(i>0 && j<n-1) {
            if(curr[i-1][j+1] == 1 || curr[i-1][j+1] == 3) liveNeighbours++;
        }
        if(i<m-1 && j>0) {
            if(curr[i+1][j-1] == 1 || curr[i+1][j-1] == 3) liveNeighbours++;
        }
        if(i<m-1 && j<n-1) {
            if(curr[i+1][j+1] == 1 || curr[i+1][j+1] == 3) liveNeighbours++;
        }
        return liveNeighbours;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
	    int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int living = getLiveNeighbours(board, i, j, m, n);
                if (board[i][j] == 0) {
                    if (living == 3) board[i][j] = 2;
                } else if (board[i][j] == 1) {
                    if (living < 2 || living > 3) board[i][j] = 3;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 2) board[i][j] = 1;
                else if (board[i][j] == 3) board[i][j] = 0;
            }
        }
    }
};