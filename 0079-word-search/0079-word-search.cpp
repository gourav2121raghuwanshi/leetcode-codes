class Solution {
    int n, m;
    bool solve(int i, int j, int idx, string& word,
               vector<vector<char>>& board) {
        if (idx >= word.size())
            return true;
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[idx] ||
            board[i][j] == '.')
            return false;
        char ch = board[i][j];
        board[i][j] = '.';
        bool ans = solve(i - 1, j, idx+1, word, board) ||
                   solve(i + 1, j, idx+1, word, board) ||
                   solve(i, j - 1, idx+1, word, board) ||
                   solve(i, j + 1, idx+1, word, board);

        board[i][j] = ch;
        return ans;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == word[0]) {
                    if (solve(i, j, 0, word, board))
                        return true;
                }
            }
        }
        return false;
    }
};