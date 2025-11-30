class Solution {
public:
    vector<int> coordinates (int x, int n) {
        int row = n - (x-1)/n-1;
        int col = (x-1) % n;
        if(row % 2 == n % 2)
            return {row, n - col - 1};
        return {row, col};
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        set<vector<int>> hash;
        queue<int> q;
        q.push(1);
        hash.insert({(int)board.size() - 1, 0});
        int steps = 0;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                int x = q.front();
                q.pop();
                if(x == n * n) return steps;
                for(int i = 1; i <= 6; i++) {
                    vector<int> curr;
                    if(i + x > n * n) break;
                    curr = coordinates(x + i, n);
                    if(hash.count(curr)) continue;
                    hash.insert(curr);
                    if(board[curr[0]][curr[1]] != -1)
                        q.push(board[curr[0]][curr[1]]);
                    else
                        q.push(x + i);
                }
            }
            steps++;
        }
        return -1;
    }
};