class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;

        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char val = board[i][j];

                if (val == '.') continue;

                if (rows[i].count(val)) return false;

                rows[i].insert(val);

                if (cols[j].count(val)) return false;

                cols[j].insert(val);

                int idx = (i / 3) * 3 + (j / 3);
                if (boxes[idx].count(val)) return false;

                boxes[idx].insert(val);
            }
        }
        return true;
    }
};