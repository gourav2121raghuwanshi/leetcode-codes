class Solution {
    int n, m;
    bool solve(int i, int j, int idx, vector<vector<char>>& board,
               string& word) {
        if (idx == word.size())
            return true;
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] == '*' ||
            word[idx] != board[i][j]) {
            return false;
        }
        char ch = board[i][j];
        board[i][j] = '*';
        bool ans = solve(i + 1, j, idx + 1, board, word);
        if (ans)
            return true;
        ans |= solve(i - 1, j, idx + 1, board, word);
        if (ans)
            return true;
        ans |= solve(i, j - 1, idx + 1, board, word);
        if (ans)
            return true;
        ans |= solve(i, j + 1, idx + 1, board, word);
        board[i][j] = ch;
        if (ans)
            return true;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == word[0]) {
                    if (solve(i, j, 0, board, word))
                        return true;
                }
            }
        }
        return false;
    }
};