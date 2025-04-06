class Solution {
    vector<vector<string>> ans;

    bool valid(int i, int j, vector<string>& board, int n) {

        for (int k = 0; k < n; ++k) {
            if (board[k][j] == 'Q')
                return false;
            if (board[i][k] == 'Q')
                return false;
        }
        int a = i;
        int b = j;
        while (a >= 0 && b >= 0) {
            if (board[a][b] == 'Q')
                return false;
            --a, --b;
        }
        a = i;
        b = j;
        while (a >= 0 && b < n) {
            if (board[a][b] == 'Q')
                return false;
            --a, ++b;
        }
        return true;
    }
    void solve(int row, int n, vector<string>& board) {
        if (row >= n) {
            ans.push_back(board);
            return;
        }
        for (int j = 0; j < n; ++j) {
            if (valid(row, j, board, n)) {
                board[row][j] = 'Q';
                solve(row + 1, n, board);
                board[row][j] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        string v(n, '.'); //. => empty block
        vector<string> board;
        for (int i = 0; i < n; i++)
            board.push_back(v);
        solve(0, n, board);
        return ans;
    }
};